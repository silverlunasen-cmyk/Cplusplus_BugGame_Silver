//
// Created by Sysadmin on 07/05/2026.
//

#include "Vampire.h"

using namespace std;
void VampireBug::move()
{
    while (isBlocked())
    {
        facing = static_cast<direction>((rand() % 4) + 1);
    }
    int dist = (rand() % 3) + 1;

    if (facing == north)      position.second -= dist;
    else if (facing == south) position.second+= dist;
    else if (facing == east)  position.first+= dist;
    else if (facing == west)  position.first-= dist;



    if (position.first < 0)
    {
        position.first = 0;
        blocked = true;
        cout << "you hit a wall! ";
    }
    ;
    if (position.first > 9)
    {
        position.first = 9;
        blocked = true;
        cout << "you hit a wall! ";
    }
    if (position.second < 0)
    {
        position.second = 0;
        blocked = true;
        cout << "you hit a wall! ";
    }
    if (position.second > 9)
    {
        position.second = 9;
        blocked = true;
        cout << "you hit a wall! ";
    }

    previousPath.push_back(position);
}

void VampireBug::drainHealth(Bug* victim)
{
    int stealAmount = 5;
    victim->setHealth(victim->getHealth() - stealAmount);
    this->setHealth(this->getHealth() + stealAmount);
    cout << "The vampire " << id << " sucked 5 HP from Bug " << victim->getId() << "!" << endl;
}

void VampireBug::display() const
{
    string dirName[] = {"", "North", "South", "East", "West"};
    string status;
    if (health < 0)
    {
        status = "Dead";
    }
    else
    {
        status = "Alive";
    }
    cout << id << " Vampire (" << position.first << "," << position.second << ") " << " HP: " << health << " " << status << endl;
}