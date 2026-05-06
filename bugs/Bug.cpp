#include "Bug.h"

Bug::Bug(int id, int x, int y, enum direction dir, int h)
    : id(id), position({x, y}), facing(dir), health(h), alive(true)
{
    previousPath.push_back(position);
}

void Bug::displayHistory(std::ostream& out) const
{
    bool first = true;
    for (const auto& pos : previousPath)
    {
        if (!first)
        {
            out << ", ";
        }
        out << "(" << pos.first << "," << pos.second << ")";
        first = false;
    }

    if (!isAlive())
    {
        out << " (Dead)";
    }
    else
    {
        out << " (Alive)";
    }
}

bool Bug::isAlive() const
{
    return health > 0;
}

bool Bug::isBlocked() const
{
    if (facing == north && position.second <= 0) return true;
    if (facing == south && position.second >= 9) return true;
    if (facing == east  && position.first >= 9) return true;
    if (facing == west  && position.first <= 0) return true;
    return false;
}