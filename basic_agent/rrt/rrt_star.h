#ifndef RRT_STAR_H
#define RRT_STAR_H

#include "rrt_support.h"
#include <vector>

// FUNZIONE ALGORITMO RRT
double getRand01();
int rrt_star(node start, node goal, std::vector<obstacle> &obstacles, std::vector<node> &path_car);

#endif