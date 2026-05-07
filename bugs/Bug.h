#ifndef CPLUSPLUS_BUGGAME_SILVER_BUG_H
#define CPLUSPLUS_BUGGAME_SILVER_BUG_H

#include <iostream>
#include <list>
#include <utility>

using namespace std;

enum direction {north = 1, south = 2, east = 3, west = 4};

class Bug
{
protected:
    int id;
    std::pair<int, int> position;
    direction facing;
    int health;
    bool alive;
    list<pair<int, int>> previousPath;
    bool blocked;

public:
    Bug(int id, int x, int y, enum direction dir, int h);
    virtual ~Bug() {}

    void displayHistory(ostream& out = cout) const;
    
    virtual void display() const = 0;
    virtual void move() = 0;

    int getId() const { return id; }
    pair<int, int> getPosition() const { return position; }
    int getHealth() const
    {
        return health;
    }

    void setHealth(int h)
    {
        health = h;
        if (health <= 0)
        {
            health = 0;
            alive = false;
        }
    }

    virtual void drainHealth(Bug* victim) {}
    bool isAlive() const;
    bool isBlocked() const;
};

#endif