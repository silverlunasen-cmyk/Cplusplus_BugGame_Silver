//
// Created by Sysadmin on 03/05/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_BUG_H
#define CPLUSPLUS_BUGGAME_SILVER_BUG_H
#include <iostream>
#include <list>
#include <utility>

enum direction {north = 1, south = 2, east = 3, west = 4};

class Bug
{
protected:
    int id;
    std::pair<int, int> position;
    direction facing;
    int health;
    bool alive;
    std::list<std::pair<int, int>> previousPath;
    bool blocked;


public:
    Bug(int id, int x, int y, enum direction dir, int h)
            : id(id), position({x, y}), facing(dir), health(h), alive(true)
    {
        previousPath.push_back(position);
    }
    virtual ~Bug() {}

    void displayHistory(std::ostream& out = std::cout)
    {
        bool first = true;
        for (const auto& pos : previousPath)
        {
            if (!first)
                {
                std::cout << ", ";
            }
            std::cout << "(" << pos.first << "," << pos.second << ")";
            first = false;
        }

        if (!isAlive())
        {
            std::cout << " (Dead)";
        }
        else
        {
            std::cout << " (Alive)";
        }
    }

    virtual void display() = 0;
    virtual void move() = 0;


    int getId() const { return id; }

    std::pair<int, int> getPosition() const { return position; }
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
        if (facing == north && position.second <= 0) return true;
        if (facing == south && position.second >= 9) return true;
        if (facing == east  && position.first >= 9) return true;
        if (facing == west  && position.first <= 0) return true;
        return false;

    }


};



#endif //CPLUSPLUS_BUGGAME_SILVER_BUG_H