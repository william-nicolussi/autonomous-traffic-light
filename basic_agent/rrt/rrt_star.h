#ifndef RRT_STAR_H
#define RRT_STAR_H

#include "rrt_support.h"
#include <vector>

double getRand01();
node getRandomNodeInRoad(std::vector<road_segment> &road);
int rrt_star(node start, node goal, std::vector<road_segment> &road, std::vector<obstacle> &obstacles, std::vector<node> &path_car);

#endif