/* ----- RRT* ALGORITHM ----- */

#include "rrt_star.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

#define MAX_ITER 20000 // max n. of iterations

double getRand01() // random in [0,1]
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int rrt_star(node start, node goal, std::vector<obstacle> &obstacles, std::vector<node> &path_car)
{
    csvObstacle(obstacles);
    csvEndNode(goal);
    FILE *fileTree = fopen("../rrt/tree.csv", "w");
    fprintf(fileTree, "x, y, cost, index, parent_index;\n");
    FILE *filePath = fopen("../rrt/paths.csv", "w");
    fprintf(filePath, "path_nbr, x, y, cost, index, parent_index;\n");

#ifdef DEBUG
    FILE *fileDebug = fopen("../rrt/debugRTT_star.txt", "w"); // file for debug purposes
    fprintf(fileDebug, "rrt_star START\n");
#endif

    int number_of_nodes = 0;
    int numberSolutions = 0;
    std::vector<node> all_nodes;
    all_nodes.reserve(MAX_ITER + 1); // avoid execution stops due to too many iterations
    double distance;

    // set starting point
    node root = start;
    root.cost = 0.0; // cost from start to start = 0
    root.index = 0;  // root is the node number 0
    root.parent_index = -1;
    all_nodes.push_back(root);
    fprintf(fileTree, "%f, %f, %f, %d, %d;\n", root.p.x, root.p.y, root.cost, root.index, root.parent_index);

    bool goal_found = false;
    int best_goal_index = -1;
    double best_goal_cost;
    const double max_X = goal.p.x;

    for (int iter = 0; iter < MAX_ITER; iter++)
    {
#ifdef DEBUG
        fprintf(fileDebug, "iter=%d:\n", iter);
#endif
        // get random node
        node random;
        random.p.x = getRand01() * max_X;                                           
        random.p.y = getRand01() * (TOP_ROADWAY - BOTTOM_ROADWAY) + BOTTOM_ROADWAY;

        node closest = getClosestNode(all_nodes, random);

        /* STEER ->
                    new node with distance <= s_max
                    if distance <= s_max, then return random */
        node extended = extend(random, closest);
        node bestParent = getLeastCostNodeInBall(extended, closest, all_nodes);

#ifdef DEBUG
        fprintf(fileDebug, "random.x=%f, random.y=%f\n", random.p.x, random.p.y);
        fprintf(fileDebug, "closest.x=%f, closest.y=%f\n", closest.p.x, closest.p.y);
        fprintf(fileDebug, "extended.x=%f, extended.y=%f\n", extended.p.x, extended.p.y);
        fprintf(fileDebug, "bestParent.x=%f, bestParent.y=%f\n", bestParent.p.x, bestParent.p.y);
#endif

        if (!isObstacle(bestParent, extended, obstacles))
        {
#ifdef DEBUG
            fprintf(fileDebug, "ENTERED\tif(!isObstacle(bestParent, extended, obstacles))\n");
#endif
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
            fprintf(fileTree, "%f, %f, %f, %d, %d;\n", extended.p.x, extended.p.y, extended.cost, extended.index, extended.parent_index);

            // GOAL CHECK: did we reach (a small ball) containing the goal?
            double dist_to_goal = getDistance(extended, goal);

            if (dist_to_goal <= GOAL_THRESHOLD)
            {
                if (!goal_found || extended.cost < best_goal_cost)
                {
#ifdef DEBUG
                    fprintf(fileDebug, "(!goal_found || extended.cost < best_goal_cost)");
#endif
                    numberSolutions++;
                    goal_found = true;
                    best_goal_cost = extended.cost;
                    best_goal_index = extended.index;

                    path_car.clear();

                    int idx = best_goal_index;

                    /* BUILD THE PATH
                        -> add the nodes of the path in the vector,
                        then reverse the vector in order to have path_car=[goal, ..., root]*/
                    while (idx != -1)
                    {
                        path_car.push_back(all_nodes[idx]);
                        idx = all_nodes[idx].parent_index;
                    }
                    std::reverse(path_car.begin(), path_car.end());

                    // save path_car into a file
                    for (int i = 0; i < path_car.size(); i++)
                    {
                        fprintf(filePath, "%d, %f, %f, %f, %d, %d;\n", 
                            numberSolutions, 
                            path_car[i].p.x, path_car[i].p.y, 
                            path_car[i].cost, path_car[i].index, 
                            path_car[i].parent_index);
                    }
                }
            }
        }
    }
#ifdef DEBUG
    fprintf(fileDebug, "rrt_star FINISHED");
    fclose(fileDebug);
#endif
    fclose(filePath);
    fclose(fileTree);

    return numberSolutions;
}