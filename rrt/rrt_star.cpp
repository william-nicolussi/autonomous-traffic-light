/* ----- RRT* ALGORITHM ----- */

#include "rrt_star.h"

#include <algorithm>
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
    double distance;

    // set starting point
    node root = start;
    root.cost = 0.0; // cost from start to start = 0
    root.index = 0;  // root is the node number 0
    root.parent_index = -1;
    all_nodes.push_back(root);

    bool goal_found = false;
    int best_goal_index = -1;
    double best_goal_cost;

    for (int iter = 0; iter < MAX_ITER; iter++)
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
        node bestParent = getLeastCostNodeInBall(extended, closest, all_nodes);

        if (!isObstacle(bestParent, extended, obstacles))
        {
            number_of_nodes++;
            extended.parent_index = bestParent.index;
            extended.index = number_of_nodes;
            extended.cost = bestParent.cost + getDistance(bestParent, extended);
            all_nodes.push_back(extended);

            /* REWIRING ->
                        try upgrade nodes in ball using extended as new parent */
            for (node &nd : all_nodes)
            {
                if (nd.index != extended.index) // avoid self rewiring
                {
                    distance = getDistance(extended, nd);

                    if (distance <= R_NEAR)
                    {
                        double cost_through_extended = extended.cost + distance;

                        if (cost_through_extended < nd.cost) // new cost is better than before
                        {
                            if (!isObstacle(extended, nd, obstacles)) // check rewired arc is collision-free
                            {
                                nd.parent_index = extended.index;
                                nd.cost = cost_through_extended;
                            }
                        }
                    }
                }
            }

            // GOAL CHECK: extended è abbastanza vicino al goal?
            // GOAL CHECK: extended è abbastanza vicino al goal?
            double dist_to_goal = getDistance(extended, goal);

            if (dist_to_goal <= GOAL_THRESHOLD)
            {
                if (!goal_found || extended.cost < best_goal_cost)
                {
                    goal_found = true;
                    best_goal_cost = extended.cost;
                    best_goal_index = extended.index;

                    path_car.clear();

                    int idx = best_goal_index;

                    // costruiamo il path al contrario: goal -> ... -> root
                    while (idx != -1)
                    {
                        path_car.push_back(all_nodes[idx]);
                        idx = all_nodes[idx].parent_index;
                    }

                    // ora path_car è [goal, ..., root], quindi invertiamo
                    std::reverse(path_car.begin(), path_car.end());
                }
            }
        }
    }
}