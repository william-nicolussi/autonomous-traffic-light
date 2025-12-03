/* ----- FUNCTIONS FOR RRT ----- */

#include "rrt_support.h"
#include <cmath>

// -- return true if the segment of two nodes intersects ANY obstacle --
bool isObstacle(node start_node, node end_node, std::vector<obstacle> &obstacles)
{
    for (obstacle obs : obstacles) // check collision with each obstacle
    {
        if (segmentIntersectsObstacle(start_node, end_node, obs))
        {
            return true;
        }
    }
    return false;
}

// -- return true if point intersects ONE obstacle --
bool segmentIntersectsObstacle(node n1, node n2, obstacle obs)
{
    point A, B;
    A.x = n1.p.x;
    A.y = n1.p.y;
    B.x = n2.p.x;
    B.y = n2.p.y;

    const double x_offset = X_OFFSET;
    const double y_offset = Y_OFFSET;

    double cx = obs.x;     // x of the CENTER of the obstacle
    double cy = obs.y;     // y of the CENTER of the obstacle
    double L = obs.lenght; // lenght of the obstacle
    double W = obs.width;  // width of the obstacle

    double L_half = L / 2.0;
    double W_half = W / 2.0;

    // vertexes defining the rectangle representing the obstacle
    // v1 --- v2
    // |      |
    // v3 --- v4
    point v1, v2, v3, v4;
    v1.x = cx - L_half - x_offset;
    v1.y = cy + W_half + y_offset;
    v2.x = cx + L_half + x_offset;
    v2.y = cy + W_half + y_offset;
    v3.x = cx - L_half - x_offset;
    v3.y = cy - W_half - y_offset;
    v4.x = cx + L_half + x_offset;
    v4.y = cy - W_half - y_offset;

    if (segmentIntersectsRect(A, B, v1, v2, v3, v4)) // if segment AB intercept rectangle v1...v4
    {
        return true;
    }

    // check point B (new point) is on the road
    if (B.y > TOP_ROAD)
    {
        return true;
    }

    if (B.y < BOTTOM_ROAD)
    {
        return true;
    }
    return false;
}

bool segmentIntersectsRect(point A, point B, point v1, point v2, point v3, point v4)
{
    // vertexes must be in this shape, otherwise it does not work
    // v1 --- v2
    // |      |
    // v3 --- v4

    // check if nodes inside the obstacle
    if (pointInsideObstacle(A, v1, v4))
    {
        return true;
    }
    if (pointInsideObstacle(B, v1, v4))
    {
        return true;
    }

    // check intersection with one of the 4 sides of the rectangle
    if (segmentsIntersect(A, B, v1, v2)) // TOP SIDE -> v1-v2
    {
        return true;
    }
    else if (segmentsIntersect(A, B, v3, v4)) // BOTTOM SIDE -> v3-v4
    {
        return true;
    }
    else if (segmentsIntersect(A, B, v1, v3)) // LEFT SIDE -> v1-v3
    {
        return true;
    }
    else if (segmentsIntersect(A, B, v2, v4)) // RIGHT SIDE -> v2-v4
    {
        return true;
    }

    // if we arrive here, there is no intersection
    return false;
}

// -- check if the point is inside the obstacle --
bool pointInsideObstacle(point P, point v1, point v4)
{
    if (v1.x <= P.x && P.x <= v4.x)
    {
        if (v1.y >= P.y && P.y >= v4.y)
        {
            // P.x in [v1.x; v4.x] && P.y in [v4.y; v1.y]
            return true;
        }
    }
    return false;
}

// -- check if segment AB intersect segment CD --
bool segmentsIntersect(point A, point B, point C, point D)
{
    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);

    if (o1 != o2 && o3 != o4)
    {
        return true;
    }

    // case COLINEARS NOT CONSIDERED -> borders never overlap.
    return false;
}

// -- return number sayng R is left, right, allineate with segment PQ --
int orientation(point P, point Q, point R)
{
    double val = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);

    const double EPS = 1e-9; // remember double==0 does not always work -> use threshold
    if (fabs(val) < EPS)
    {
        return POINTS_COLLINEARS; // points are collinears
    }
    else if (val > 0)
    {
        return POINTS_CLOCKWISE;
    }
    else
    {
        return POINTS_ANTICLOCKWISE;
    }
}

// -- return distance between two nodes --
double getDistance(node random, node closest)
{
    double x1 = random.p.x;
    double y1 = random.p.y;
    double x2 = closest.p.x;
    double y2 = closest.p.y;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

/* ------------------------- */
double getMin(double n1, double n2)
{
    double min;
    if (n1 < n2)
    {
        min = n1;
    }
    else
    {
        min = n2;
    }
    return min;
}

double getMax(double n1, double n2)
{
    double max;
    if (n1 > n2)
    {
        max = n1;
    }
    else
    {
        max = n2;
    }
    return max;
}

// -- get closest node to x_new --
node getClosestNode(std::vector<node> &nodevec, node x_new)
{
    node closestNode = nodevec[0];
    double minDistance = getDistance(x_new, nodevec[0]);
    double distance;

    for (node nd : nodevec)
    {
        distance = getDistance(x_new, nd);

        if (distance < minDistance)
        {
            minDistance = distance;
            closestNode = nd;
        }
    }
    return closestNode;
}

// -- extend the closest node to a random node --
node extend(node random, node closest)
{
    // pick the closest node to the random one and extend it in order to built the tree
    // min_distance is the minimum lenght of the branch

    double distance = getDistance(random, closest);
    node ext;
    const double EPS = 1e-9;

    if (distance > EPS) // (distance != 0)
    {
        /* FORMULAS ->
                x = x1+(x2-x1)*(smax/dist)
                y = y1+(y2-y1)*(smax/dist) */
        ext.p.x = closest.p.x + fabs(random.p.x - closest.p.x) * min_distance / distance; // search only to the right
        ext.p.y = closest.p.y + (random.p.y - closest.p.y) * min_distance / distance;
    }
    else
    {
        ext = closest;
    }

    return ext;
}

/* ------------------------- */
double path_cost(std::vector<node> &nodevec, std::vector<node> &nodevec_par, int num_node, std::vector<node> &path)
{
    int i = num_node;
    double cost = 0.0;
    path.push_back(nodevec[i]);

    while (i != 0)
    {
        node last = nodevec[i];         // Vettore nodi
        node last_par = nodevec_par[i]; // Vettore parent dei nodi

        path.push_back(last_par);

        cost += getDistance(last, last_par);

        // A partire dall'ultimo punto del vettore, continuo a seguire il parent fino a che non raggiungo il punto di partenza, calcolando il costo come distanza percorsa.

        for (int j = 0; j < i; j++)
        {
            if ((nodevec[j].p.x == last_par.p.x) && (nodevec[j].p.y == last_par.p.y))
            {
                i = j;
            }
        }
    }

    return cost;
}
/* ------------------------- */