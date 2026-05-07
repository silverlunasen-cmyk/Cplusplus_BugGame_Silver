#include "Crawler.h"
using namespace std;

void Crawler::move()
{
        while (isBlocked())
        {
            facing = static_cast<direction>((rand() % 4) + 1);
        }
        if (facing == north)
            position.second -= 1;
        else if (facing == south)
            position.second += 1;
        else if (facing == east)
            position.first += 1;
        else if (facing == west)
            position.first -= 1;
        previousPath.push_back(position);
}

void Crawler::display() const
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
    cout << id << " Crawler (" << position.first << "," << position.second << ") "
              << health << " " << dirName[facing] << " " << status << endl;
}
