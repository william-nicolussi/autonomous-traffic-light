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
    struct node *parent;
} node;

// -- obstacle is a rectangle --
typedef struct
{
    double x, y; // coordinates of the CENTER
    double lenght;
    double width;
} obstacle;

/* ----- CONSTANTS ----- */
#define X_OFFSET 35.0
#define Y_OFFSET 4.5
#define TOP_ROAD 35.0
#define BOTTOM_ROAD 5.0
#define POINTS_COLLINEARS 0
#define POINTS_CLOCKWISE 1
#define POINTS_ANTICLOCKWISE 2
#define min_distance 10.0 // = distance*10 -> min distance between two nodes of the tree

/* ----- FUNCTIONS FOR RRT ----- */
bool isObstacle(node start_node, node end_node, std::vector<obstacle> &obstacles);
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
double path_cost(std::vector<node> &nodevec, std::vector<node> &nodevec_par, int num_node, std::vector<node> &path);

#endif