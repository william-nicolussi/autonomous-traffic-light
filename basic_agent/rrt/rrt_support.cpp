/* ----- FUNCTIONS FOR RRT ----- */

#include "rrt_support.h"
#include <cmath>
#include <cstdio>

// #define DEBUG

// -- return true if the nodes and the segments are on the road --
bool isOnRoad(node &start_node, node &end_node, std::vector<road_segment> &road)
{
    // check nodes are on road
    if (!isNodeOnAnyRoad(start_node, road))
    {
        return false;
    }
    if (!isNodeOnAnyRoad(end_node, road))
    {
        return false;
    }

    double dist = getDistance(start_node, end_node);

    // if segment is very small do not check the segment
    if (dist < DIST_SEGMENT_SMALL)
    {
        return true;
    }

    // discretize the segment to check if it is on the road
    int steps = (int)(dist / CHECK_SEGMENT_STEP);
    double dx = (end_node.p.x - start_node.p.x) / steps;
    double dy = (end_node.p.y - start_node.p.y) / steps;
    node nd = start_node;
    for (int i = 1; i < steps; i++)
    {
        nd.p.x += dx;
        nd.p.y += dy;
        if (!isNodeOnAnyRoad(nd, road))
        {
            return false;
        }
    }
    return true;
}

// -- return true if the segment of two nodes intersects ANY obstacle --
bool isObstacle(node &start_node, node &end_node, std::vector<obstacle> &obstacles)
{
#ifdef DEBUG
    FILE *fileDebug = fopen("../rrt/debugIsObstacle.txt", "a"); // file for debug purposes
    fprintf(fileDebug, "isObstacleDebug START\n");
    int numberObstacles = 0;
    fprintf(fileDebug, "start_node.x=%f; start_node.y=%f\n", start_node.p.x, start_node.p.y);
    fprintf(fileDebug, "end_node.x=%f; end_node.y=%f\n", end_node.p.x, end_node.p.y);
#endif

    for (obstacle obs : obstacles) // check collision with each obstacle
    {
#ifdef DEBUG
        numberObstacles++;
        fprintf(fileDebug, "numerObstacles = %d\n", numberObstacles);
        fprintf(fileDebug, "obs.x=%f; obs.y=%f\n", obs.x, obs.y);
#endif
        if (segmentIntersectsObstacle(start_node, end_node, obs))
        {
#ifdef DEBUG
            fprintf(fileDebug, "isObstacleDebug FINISHED TRUE\n\n");
            fclose(fileDebug);
#endif
            return true;
        }
    }
#ifdef DEBUG
    fprintf(fileDebug, "isObstacleDebug FINISHED FALSE\n\n");
    fclose(fileDebug);
#endif
    return false;
}

// -- return true if point intersects ONE obstacle --
bool segmentIntersectsObstacle(node &n1, node &n2, obstacle &obs)
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
    double L = obs.length; // lenght of the obstacle
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

#ifdef DEBUG
    FILE *fileDebug = fopen("../rrt/print_obstacles.txt", "a"); // file for debug purposes
    fprintf(fileDebug, "print_obstacles START\n");
    fprintf(fileDebug, "v1.x=%f, v1.y=%f\n", v1.x, v1.y);
    fprintf(fileDebug, "v2.x=%f, v2.y=%f\n", v2.x, v2.y);
    fprintf(fileDebug, "v3.x=%f, v3.y=%f\n", v3.x, v3.y);
    fprintf(fileDebug, "v4.x=%f, v4.y=%f\n", v4.x, v4.y);
#endif

    if (segmentIntersectsRect(A, B, v1, v2, v3, v4)) // if segment AB intercept rectangle v1...v4
    {
#ifdef DEBUG
        fprintf(fileDebug, "return true\t\tsegmentIntersectsRect(A, B, v1, v2, v3, v4)");
        fprintf(fileDebug, "print_obstacles FINISHED\n\n");
        fclose(fileDebug);
#endif
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

// -- check if a node is inside a segment --
bool nodeInsideRoadSegment(node &nd, road_segment &seg)
{
    point P = nd.p; // coordinates of the node
    point v1, v4;

    double half_L = seg.length / 2.0;
    double half_W = seg.width / 2.0;

    // v1 -> TOP LEFT
    v1.x = seg.x - half_L;
    v1.y = seg.y + half_W;

    // v4 -> BOTTOM RIGHT
    v4.x = seg.x + half_L;
    v4.y = seg.y - half_W;

    // use the function to check if the point is inside a rectangle
    return pointInsideObstacle(P, v1, v4);
}

// -- check if a nod is inside any of the existing segments --
bool isNodeOnAnyRoad(node &nd, std::vector<road_segment> &road)
{
    for (road_segment &seg : road)
    {
        if (nodeInsideRoadSegment(nd, seg))
        {
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
double getDistance(node &random, node &closest)
{
    double x1 = random.p.x;
    double y1 = random.p.y;
    double x2 = closest.p.x;
    double y2 = closest.p.y;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// -- return weighted distance --
double getWeightedDistance(node &nd1, node &nd2, std::vector<road_segment> &segments)
{
    double dist = getDistance(nd1, nd2);
    double multiplier = 1.0;
    for (road_segment &seg : segments)
    {
        if (nodeInsideRoadSegment(nd2, seg))
        {
            multiplier = seg.cost;
            break;
        }
    }
    return dist * multiplier;
}

// -- get closest node to x_new --
node getClosestNode(std::vector<node> &nodevec, node &x_new)
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
node extend(node &random, node &closest)
{
    // pick the closest node to the random one and extend it in order to built the tree
    // min_distance is the minimum lenght of the branch
    double distance = getDistance(random, closest);
    node ext;
    const double EPS = 1e-9;

    if (distance <= min_distance)
    {
        ext.p.x = random.p.x;
        ext.p.y = random.p.y;
    }
    else
    {
        /* FORMULAS ->
                x = x1+(x2-x1)*(smax/dist)
                y = y1+(y2-y1)*(smax/dist) */
        ext.p.x = closest.p.x + (random.p.x - closest.p.x) * min_distance / distance;
        ext.p.y = closest.p.y + (random.p.y - closest.p.y) * min_distance / distance;
    }

    return ext;
}

// -- return the note in the ball with center new_node with the minumum cost --
node getLeastCostNodeInBall(node &new_node, node &closest, std::vector<node> &nodevec)
{
    node minCostNode = closest;
    double minTotalCost = closest.cost + getDistance(closest, new_node);
    double distance, totalCost;
    for (node nd : nodevec)
    {
        distance = getDistance(nd, new_node);
        if (distance <= R_NEAR)
        {
            totalCost = nd.cost + distance;
            if (totalCost < minTotalCost)
            {
                minTotalCost = totalCost;
                minCostNode = nd;
            }
        }
    }
    return minCostNode;
}

void csvNode(const char *nameFile, node &nd)
{
    FILE *fileNode = fopen(nameFile, "w");
    fprintf(fileNode, "x, y, GOAL_THRESHOLD;\n");
    fprintf(fileNode, "%f, %f;\n", nd.p.x, nd.p.y);
    fclose(fileNode);
}

void csvEndNode(node &goal)
{
    FILE *fileEndNode = fopen("../rrt/endNode.csv", "w");
    fprintf(fileEndNode, "x, y, GOAL_THRESHOLD;\n");
    fprintf(fileEndNode, "%f, %f, %f;\n", goal.p.x, goal.p.y, GOAL_THRESHOLD);
    fclose(fileEndNode);
}

void csvObstacle(std::vector<obstacle> &obstacles)
{
    /* Obstacle is a ractangle with vertexes ob1, ob2, ob3, ob4.
    Enlarged obstacle (using OFFSETS) has v1, v2, v3, v4*/
    FILE *fileObstacle = fopen("../rrt/obstacles.csv", "w");
    fprintf(fileObstacle, "ID, cx, cy, L, W, ");
    fprintf(fileObstacle, "ob1_x, ob1_y, ob2_x, ob2_y, ob3_x, ob3_y, ob4_x, ob4_y, ");
    fprintf(fileObstacle, "v1_x, v1_y, v2_x, v2_y, v3_x, v3_y, v4_x, v4_y;\n");

    for (obstacle obs : obstacles)
    {
        const double x_offset = X_OFFSET;
        const double y_offset = Y_OFFSET;

        double cx = obs.x;     // x of the CENTER of the obstacle
        double cy = obs.y;     // y of the CENTER of the obstacle
        double L = obs.length; // lenght of the obstacle
        double W = obs.width;  // width of the obstacle
        fprintf(fileObstacle, "%d, %f, %f, %f, %f, ", obs.ID, cx, cy, L, W);

        double L_half = L / 2.0;
        double W_half = W / 2.0;

        point ob1, ob2, ob3, ob4;
        ob1.x = cx - L_half;
        ob1.y = cy + W_half;
        ob2.x = cx + L_half;
        ob2.y = cy + W_half;
        ob3.x = cx - L_half;
        ob3.y = cy - W_half;
        ob4.x = cx + L_half;
        ob4.y = cy - W_half;
        fprintf(fileObstacle, "%f, %f, %f, %f, %f, %f, %f, %f, ", ob1.x, ob1.y, ob2.x, ob2.y, ob3.x, ob3.y, ob4.x, ob4.y);

        point v1, v2, v3, v4;
        v1.x = ob1.x - x_offset;
        v1.y = ob1.y + y_offset;
        v2.x = ob2.x + x_offset;
        v2.y = ob2.y + y_offset;
        v3.x = ob3.x - x_offset;
        v3.y = ob3.y - y_offset;
        v4.x = ob4.x + x_offset;
        v4.y = ob4.y - y_offset;
        fprintf(fileObstacle, "%f, %f, %f, %f, %f, %f, %f, %f;\n", v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y);
    }
    fclose(fileObstacle);
}

void csvRoad(std::vector<road_segment> &road)
{
    /* Obstacle is a ractangle with vertexes ob1, ob2, ob3, ob4.
    Enlarged obstacle (using OFFSETS) has v1, v2, v3, v4*/
    FILE *fileRoad = fopen("../rrt/road.csv", "w");
    fprintf(fileRoad, "ID, cx, cy, L, W, ");
    // fprintf(fileRoad, "ob1_x, ob1_y, ob2_x, ob2_y, ob3_x, ob3_y, ob4_x, ob4_y, ");
    fprintf(fileRoad, "v1_x, v1_y, v2_x, v2_y, v3_x, v3_y, v4_x, v4_y;\n");

    for (road_segment seg : road)
    {
        double cx = seg.x; // x of the CENTER
        double cy = seg.y; // y of the CENTER
        double L = seg.length;
        double W = seg.width;
        fprintf(fileRoad, "%d, %f, %f, %f, %f, ", seg.ID, cx, cy, L, W);

        double L_half = L / 2.0;
        double W_half = W / 2.0;

        point v1, v2, v3, v4;
        v1.x = cx - L_half;
        v1.y = cy + W_half;
        v2.x = cx + L_half;
        v2.y = cy + W_half;
        v3.x = cx - L_half;
        v3.y = cy - W_half;
        v4.x = cx + L_half;
        v4.y = cy - W_half;
        fprintf(fileRoad, "%f, %f, %f, %f, %f, %f, %f, %f;\n", v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y);
    }
    fclose(fileRoad);
}