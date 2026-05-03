//
// Created by Sysadmin on 03/05/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_HOPPER_H
#define CPLUSPLUS_BUGGAME_SILVER_HOPPER_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "../bugs/Bug.h"


class Hopper: public Bug
{
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, enum direction dir, int health, int hopLength): Bug(id, x, y, dir, health), hopLength(hopLength)
    {};

    void move() override
    {
        while (blocked)
        {
            direction == (rand() % 4) + 1;

        }
        for (int i = 0; i < hopLength; i++)
        {
            if (blocked)
            {
                break;
            }
            if (direction == north) position.second =+ hopLength;
            else if (direction == south) position.second =- hopLength;
            else if (direction == east) position.first =+ hopLength;
            else if (direction == west) position.first =- hopLength;

        }
        previousPath.push_back(position);

    }
    void display() override
    {
        std::string status = (health > 0) ? "Alive" : "Dead";
        std::string dirName[] = {"", "North", "South", "East", "West"};

        std::cout << id << " Hopper (" << position.first << "," << position.second << ") "
                  << dirName[direction] << "" << health << " " << " " << hopLength << " " << status << std::endl;
    };

};


#endif //CPLUSPLUS_BUGGAME_SILVER_HOPPER_H