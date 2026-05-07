#include "Hopper.h"
using namespace std;

Hopper::Hopper(int id, int x, int y, direction dir, int health, int hopLength)
    : Bug(id, x, y, dir, health), hopLength(hopLength) {}



void Hopper::move()
{
    while (isBlocked())
    {
        facing = static_cast<direction>((rand() % 4) + 1);
    }
    if (facing == north) position.second -= hopLength;
    else if (facing == south) position.second += hopLength;
    else if (facing == east) position.first += hopLength;
    else if (facing == west) position.first -= hopLength;

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
void Hopper::display() const
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
    cout << id << " Hopper (" << position.first << "," << position.second << ") "
              << health << dirName[facing] << " " << " " << " " << hopLength << " " << status << endl;
};