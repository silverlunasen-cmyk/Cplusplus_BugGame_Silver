//
// Created by D00280022 on 20/04/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_HOPPER_H
#define CPLUSPLUS_BUGGAME_SILVER_HOPPER_H

#include "../Bug.h"


class Hopper : public Bug
{
    private:
        int hopLength;
    public:
        int id;
        pair<int, int> position;
        int direction;
        int health;
        bool isAlive;
        list<pair<int, int>> path;
        virtual move();
        bool isWayBlocked();
};



#endif //CPLUSPLUS_BUGGAME_SILVER_HOPPER_H