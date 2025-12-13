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
    int ID;
    double x, y; // coordinates of the CENTER
    double length;
    double width;
} obstacle;

// -- road_segment is a rectangle with a cost --
typedef struct
{
    int ID;
    double x, y;
    double width, length;
    double cost;
} road_segment;

/* ----- CONSTANTS ----- */
#define X_OFFSET 0.5
#define Y_OFFSET 0.5
// #define TOP_ROADWAY 2
// #define BOTTOM_ROADWAY -2
#define POINTS_COLLINEARS 0
#define POINTS_CLOCKWISE 1
#define POINTS_ANTICLOCKWISE 2
#define min_distance 1.5            // min distance between two nodes of the tree
#define R_NEAR (2.0 * min_distance) // radius for RRT* (choose parent + rewiring)
#define GOAL_THRESHOLD min_distance // threshold to consider the goal reached
#define DIST_SEGMENT_SMALL 0.5      // set when distance between nodes is too short
#define CHECK_SEGMENT_STEP 0.2      // value to discretize a segment

/* ----- FUNCTIONS FOR RRT ----- */
bool isOnRoad(node &start_node, node &end_node, std::vector<road_segment> &road);
bool isObstacle(node &start_node, node &end_node, std::vector<obstacle> &obstacles);
bool segmentIntersectsObstacle(node &n1, node &n2, obstacle &obs);
bool segmentIntersectsRect(point A, point B, point v1, point v2, point v3, point v4);
bool pointInsideObstacle(point P, point v1, point v4);
bool nodeInsideRoadSegment(node &nd, road_segment &seg);
bool isNodeOnAnyRoad(node &nd, std::vector<road_segment> &road);
bool segmentsIntersect(point A, point B, point C, point D);
int orientation(point P, point Q, point R);
double getDistance(node &random, node &closest);
double getWeightedDistance(node &n1, node &n2, std::vector<road_segment> &segments);
node getClosestNode(std::vector<node> &nodevec, node &x_new);
node extend(node &random, node &closest);
node getLeastCostNodeInBall(node &new_node, node &closest, std::vector<node> &nodevec);
void csvNode(const char *nameFile, node &nd);
void csvEndNode(node &goal);
void csvObstacle(std::vector<obstacle> &obstacles);
void csvRoad(std::vector<road_segment> &road);

#endif