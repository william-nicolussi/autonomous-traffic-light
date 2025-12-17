#ifndef RRT_READ_H
#define RRT_READ_H

#include <vector>
#include "rrt_support.h" 

void rrt_from_csv(const char *filename, std::vector<node> &path_to_follow);

#endif