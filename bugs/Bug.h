//
// Created by D00280022 on 20/04/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_BUG_H
#define CPLUSPLUS_BUGGAME_SILVER_BUG_H

namespace std {
    class Bug
    {
    protected:
        int id;
        pair<int, int> position;
        int direction;
        int health;
        bool isAlive;
        list<pair<int, int>> path;
        virtual move();
        bool isWayBlocked();

    public:
        virtual void move();
    };
} // std

#endif //CPLUSPLUS_BUGGAME_SILVER_BUG_H