#ifndef RRT_SUPPORT_H
#define RRT_SUPPORT_H

#include <vector>

/* ----- NEW TYPES ----- */
// -- Point is 2D --
typedef struct
{
    double x;
    double y;
} point;

// -- node has coordinates, cost, parent --
typedef struct node
{
    point p;
    double cost;
    int index;        // root has index=0, first node added has index=1 and so on..
    int parent_index; // root has index=-1
} node;

// -- obstacle is a rectangle --
typedef struct
{
    double x, y; // coordinates of the CENTER
    double lenght;
    double width;
} obstacle;

/* ----- CONSTANTS ----- */
#define X_OFFSET 0.0       // 35.0
#define Y_OFFSET 0.0       // 4.5
#define TOP_ROADWAY 20     // 35.0   // cone.set_pos((1.0,2)) -> +20 è il massimo della strada
#define BOTTOM_ROADWAY -20 // 5.0 // cone.set_pos((1.0,-2)) -> -20 il minimo y
#define POINTS_COLLINEARS 0
#define POINTS_CLOCKWISE 1
#define POINTS_ANTICLOCKWISE 2
#define min_distance 10.0           // = distance*10 -> min distance between two nodes of the tree
#define R_NEAR (4.0 * min_distance) // radius for RRT* (choose parent + rewiring)

/* ----- FUNCTIONS FOR RRT ----- */
bool isObstacle(node &start_node, node &end_node, std::vector<obstacle> &obstacles);
bool segmentIntersectsObstacle(node n1, node n2, obstacle obs);
bool segmentIntersectsRect(point A, point B, point v1, point v2, point v3, point v4);
bool pointInsideObstacle(point P, point v1, point v4);
bool segmentsIntersect(point A, point B, point C, point D);
int orientation(point P, point Q, point R);
double getDistance(node random, node closest);
double getMin(double n1, double n2);
double getMax(double n1, double n2);
node getClosestNode(std::vector<node> &nodevec, node x_new);
node extend(node random, node closest);
node getLeastCostNodeInBall(node new_node, node closest, std::vector<node> &nodevec);
void csvObstacle(std::vector<obstacle> &obstacles);
double path_cost(std::vector<node> &nodevec, std::vector<node> &nodevec_par, int num_node, std::vector<node> &path);

#endif