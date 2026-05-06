#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "../bugs/Bug.h"
#include "../crawler/Crawler.h"
#include "../hopper/Hopper.h"
using namespace std;

class Bug;

class Board {
private:


    std::vector<Bug*> bug_vector;
    std::vector<Bug*> grid[10][10];

public:
    // 1. Constructor & Destructor
    Board();
    ~Board();

    void readIn();
    void displayAllBugs() const;
    void findAndDisplayBug(int id) const;
    void tap();
    void displayAllHistories() const;
    void displayCells();
    void saveHistoryToFile(const std::string& filename);
};

#endif