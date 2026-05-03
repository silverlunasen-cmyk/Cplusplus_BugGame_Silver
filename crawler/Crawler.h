//
// Created by Sysadmin on 03/05/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H
#define CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "../bugs/Bug.h"


class Crawler : public Bug
{
    public:
      using Bug::Bug;

    void move() override
    {
        while (blocked)
        {
            direction == (rand() % 4) + 1;
        }
        if (direction == north)
            position.second -= 1;
        else if (direction == south)
              position.second += 1;
        else if (direction == east)
              position.first += 1;
        else if (direction == west)
              position.first -= 1;
    }
    void display() override
    {
        std::string status = (health > 0) ? "Alive" : "Dead";
        std::string dirName[] = {"", "North", "South", "East", "West"};

        std::cout << id << " Crawler (" << position.first << "," << position.second << ") "
                  << health << " " << dirName[direction] << " " << status << std::endl;
    }

};


#endif //CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H