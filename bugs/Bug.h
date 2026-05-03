//
// Created by Sysadmin on 03/05/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_BUG_H
#define CPLUSPLUS_BUGGAME_SILVER_BUG_H
#include <list>
#include <utility>

enum direction {north = 1, south = 2, east = 3, west = 4};

class Bug
{
protected:
    int id;
    std::pair<int, int> position;
    direction direction;
    int health;
    bool alive;
    std::list<std::pair<int, int>> previousPath;
    bool blocked;


public:
    Bug(int id, int x, int y, enum direction dir, int h)
            : id(id), position({x, y}), direction(dir), health(h), alive(true)
    {
        previousPath.push_back(position);
    }
    virtual ~Bug() {}

    virtual void display() = 0;
    virtual void move() = 0;

    bool isAlive()
    {
        if (health <= 0)
        {
            return false;
        }
        return true;
    }
    bool isBlocked()
    {
        int x = position.first;
        int y = position.second;
        if (direction == 1 && position.second == 0) return true; // North
        if (direction == 2 && position.first == 9)  return true; // South
        if (direction == 3 && position.second == 9) return true; // East
        if (direction == 4 && position.first == 0)  return true; // West
    }



};



#endif //CPLUSPLUS_BUGGAME_SILVER_BUG_H