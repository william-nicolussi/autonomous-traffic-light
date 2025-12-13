#include "rrt_star_refine.h"
#include "rrt_star.h"
#include "rrt_support.h"

#include <cmath>
#include <cstdio>
#include <vector>

void rrt_star_refine(std::vector<road_segment> &road, std::vector<obstacle> &obstacles, std::vector<node> &path_car)
{
    // if path_car too short, then just return
    if (path_car.size() < 3)
    {
        return;
    }

    std::vector<node> refined_path;
    refined_path.push_back(path_car[0]);

    int anchor_idx = 0;     // node "A" (last known in the path)
    int look_ahead_idx = 1; // node "B", "C", "D"... (next candidate)

    while (anchor_idx < path_car.size() - 1)
    {
        // check to not go out of the vector
        if (look_ahead_idx >= path_car.size())
        {
            refined_path.push_back(path_car.back());
            break;
        }

        bool is_valid_extension = true;

        // if new segment intersects obstacles or is not on the road,
        // then do not calculate anything
        // otherwise check if the nodes are in a tube with radius MAX_ALIGNMENT_ERROR
        if (isObstacle(path_car[anchor_idx], path_car[look_ahead_idx], obstacles) ||
            !isOnRoad(path_car[anchor_idx], path_car[look_ahead_idx], road))
        {
            is_valid_extension = false;
        }
        else
        {
            for (int k = anchor_idx + 1; k < look_ahead_idx; k++)
            {
                double dist = getDistPointToLine(path_car[k], path_car[anchor_idx], path_car[look_ahead_idx]);
                if (dist > MAX_ALIGNMENT_ERROR)
                {
                    is_valid_extension = false;
                    break;
                }
            }
        }

        if (is_valid_extension)
        {
            look_ahead_idx++;
        }
        else
        {
            int best_node_idx = look_ahead_idx - 1;
            if (best_node_idx == anchor_idx)
            {
                best_node_idx = look_ahead_idx;
            }
            refined_path.push_back(path_car[best_node_idx]);
            anchor_idx = best_node_idx;
            look_ahead_idx = anchor_idx + 1;
        }
    }
    path_car = refined_path;

    // write path in a csv
    FILE *filePath = fopen("../rrt/path_refined.csv", "w");
    fprintf(filePath, "x, y, cost, index, parent_index;\n");
    for (int i = 0; i < path_car.size(); i++)
    {
        fprintf(filePath, "%f, %f, %f, %d, %d;\n",
                path_car[i].p.x, path_car[i].p.y,
                path_car[i].cost, path_car[i].index,
                path_car[i].parent_index);
    }
    fclose(filePath);
}

double getDistPointToLine(node P, node A, node B)
{
    double dx = B.p.x - A.p.x;
    double dy = B.p.y - A.p.y;

    // if A, B are overlapped return the distance PA
    if (fabs(dx) < 1e-9 && fabs(dy) < 1e-9)
    {
        return sqrt(pow(P.p.x - A.p.x, 2) + pow(P.p.y - A.p.y, 2));
    }

    // return the distance using point-line formula
    double num = fabs(dy * P.p.x - dx * P.p.y + B.p.x * A.p.y - B.p.y * A.p.x);
    double den = sqrt(dx * dx + dy * dy);

    return num / den;
}