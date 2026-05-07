//
// Created by Sysadmin on 07/05/2026.
//
#ifndef VAMPIREBUG_H
#define VAMPIREBUG_H

#include "../bugs/Bug.h"

class VampireBug : public Bug
{
public:
    VampireBug(int id, int x, int y, direction dir, int health)
        : Bug(id, x, y, dir, health) {}

    void move() override;
    void display() const override;

    // Unique ability: Steals 5 HP from an opponent
    void drainHealth(Bug* victim) override;


};

#endif