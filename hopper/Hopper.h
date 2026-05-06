

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
    Hopper(int id, int x, int y, enum direction dir, int health, int hopLength);

    void move() override;
    void display() override;

};


#endif //CPLUSPLUS_BUGGAME_SILVER_HOPPER_H