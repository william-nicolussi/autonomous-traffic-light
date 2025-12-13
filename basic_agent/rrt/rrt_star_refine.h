#ifndef RRT_STAR_REFINE_H
#define RRT_SRRT_STAR_REFINE_HTAR_H

#include "rrt_support.h"
#include <vector>

#define MAX_ALIGNMENT_ERROR 1 // if aligned in a tunnel with this diameter

void rrt_star_refine(std::vector<road_segment> &road, std::vector<obstacle> &obstacles, std::vector<node> &path_car);
double getDistPointToLine(node P, node A, node B);

#endif