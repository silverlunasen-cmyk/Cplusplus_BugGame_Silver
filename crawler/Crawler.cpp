#include "Crawler.h"

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

void Crawler::display()
{
    std::string status = (health > 0) ? "Alive" : "Dead";
    std::string dirName[] = {"", "North", "South", "East", "West"};

    std::cout << id << " Crawler (" << position.first << "," << position.second << ") "
              << health << " " << dirName[facing] << " " << status << std::endl;
}
