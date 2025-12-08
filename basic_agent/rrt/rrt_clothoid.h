#ifndef RRT_CLOTHOIDS_H
#define RRT_CLOTHOIDS_H

#include "Clothoids.hh"
#include "rrt_support.h"
#include <vector>

using namespace std;
using namespace G2lib;

#define DS 0.05

// FUNZIONE ALGORITMO RRT
void getClothoid(double initialYaw, vector<node> &path_to_follow, ClothoidList &path_clothoid);

#endif