#include "Hopper.h"

Hopper::Hopper(int id, int x, int y, direction dir, int health, int hopLength)
    : Bug(id, x, y, dir, health), hopLength(hopLength) {}



void Hopper::move()
{
    while (isBlocked())
    {
        facing = static_cast<direction>((rand() % 4) + 1);

    }
    if (facing == north) position.second += hopLength;
    else if (facing == south) position.second -= hopLength;
    else if (facing == east) position.first += hopLength;
    else if (facing == west) position.first -= hopLength;
    previousPath.push_back(position);

}
void Hopper::display() const
{
    std::string status = (health > 0) ? "Alive" : "Dead";
    std::string dirName[] = {"", "North", "South", "East", "West"};

    std::cout << id << " Hopper (" << position.first << "," << position.second << ") "
              << dirName[facing] << "" << health << " " << " " << hopLength << " " << status << std::endl;
};