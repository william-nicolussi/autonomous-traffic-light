/* ----- RRT* ALGORITHM ----- */

#include "rrt_star.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

#define MAX_ITER 30000              // max n. of iterations
#define GOAL_THRESHOLD min_distance // = 10.0 -> threshold to be near the goal

double getRand01() // random in [0,1]
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

void rrt_star(node start, node goal, std::vector<obstacle> &obstacles, std::vector<node> &path_car)
{
    int number_of_nodes = 0;
    std::vector<node> all_nodes;
    all_nodes.reserve(MAX_ITER + 1); // avoid execution stops due to too many iterations

    // set starting point
    node root = start;
    root.cost = 0.0; // cost from start to start = 0
    root.index = 0;  // root is the node number 0
    root.parent_index = -1;
    all_nodes.push_back(root);

    // bool goal_found = false;
    // int goal_index = -1;

    for (int iter = 1; iter < MAX_ITER; iter++)
    {
        // get random node
        node random;
        random.p.x = getRand01() * 1800.0; // 0 ... 180m * 10 // random.p.x = rand() % 1800;
        random.p.y = getRand01() * 40.0;   // random.p.y = rand() % 40;

        node closest = getClosestNode(all_nodes, random);

        /* STEER ->
                    new node with distance <= s_max
                    if distance <= s_max, then return random */
        node extended = extend(random, closest);

        if (!isObstacle(closest, extended, obstacles))
        {
            number_of_nodes++;
            extended.parent_index = closest.index;
            extended.index = number_of_nodes;
            extended.cost = closest.cost + getDistance(closest, extended);
            all_nodes.push_back(extended);
        }
    }
}