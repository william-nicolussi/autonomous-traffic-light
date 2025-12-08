/* ----- GENERATE CLOTHOID FROM RRT* NODES ----- */

#include "rrt_clothoid.h"

#include <cmath>
#include <cstdio>
#include <limits>

void getClothoid(double initialYaw, vector<node> &path_to_follow, ClothoidList &path_clothoid)
{
    FILE *fileClothoids = fopen("../rrt/clothoid.csv", "w");
    fprintf(fileClothoids, "s, x, y;\n");
    printf("Hello World");

    // Fill path_clothoid
    for (int i = 0; i < path_to_follow.size() - 1; i++)
    {
        real_type x0, y0, x1, y1, x2, y2;
        real_type theta0, theta1;
        if (i == 0) // slope for the first segment needs to take into account the initialYaw
        {
            x0 = path_to_follow[0].p.x;
            y0 = path_to_follow[0].p.y;
            x1 = path_to_follow[1].p.x;
            y1 = path_to_follow[1].p.y;
            x2 = path_to_follow[2].p.x;
            y2 = path_to_follow[2].p.y;
            theta0 = initialYaw;
            theta1 = atan2(y2 - y1, x2 - x1);
        }
        else if ((i + 2) < path_to_follow.size() - 1) // slope for segments not first nor last
        {
            x0 = path_to_follow[i].p.x;
            y0 = path_to_follow[i].p.y;
            x1 = path_to_follow[i + 1].p.x;
            y1 = path_to_follow[i + 1].p.y;
            x2 = path_to_follow[i + 2].p.x;
            y2 = path_to_follow[i + 2].p.y;
            theta0 = atan2(y1 - y0, x1 - x0);
            theta1 = atan2(y2 - y1, x2 - x1);
        }
        else // slope for last segment
        {
            x0 = path_to_follow[i].p.x;
            y0 = path_to_follow[i].p.y;
            x1 = path_to_follow[i + 1].p.x;
            y1 = path_to_follow[i + 1].p.y;
            theta0 = atan2(y1 - y0, x1 - x0);
            theta1 = theta0;
        }

        path_clothoid.push_back_G1(x0, y0, theta0, x1, y1, theta1);
    }

    // Save in the .csv
    real_type L = path_clothoid.length();
    for (real_type s = 0; s <= L; s += DS)
    {
        real_type x, y;
        path_clothoid.eval(s, x, y); // x(s), y(s)

        fprintf(fileClothoids, "%f, %f, %f;\n", s, x, y);
    }

    fclose(fileClothoids);
}