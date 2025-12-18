#include "rrt_read.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

void rrt_from_csv(const char *filename, std::vector<node> &path_to_follow)
{
    std::ifstream file(filename);
    std::string line;
    
    path_to_follow.clear();

    if (!file.is_open())
    {
        perror("CSV file did not open");
        return;
    }

    if(std::getline(file, line)) { }

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        node nd;
        char comma; 

        if (ss >> nd.p.x >> comma 
               >> nd.p.y >> comma 
               >> nd.cost >> comma 
               >> nd.index >> comma 
               >> nd.parent_index)
        {
            path_to_follow.push_back(nd);
        }
    }

    file.close();
}