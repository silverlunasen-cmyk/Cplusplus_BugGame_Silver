//
// Created by D00280022 on 20/04/2026.
//

#include "Board.h"
#include "../crawler/Crawler.h"
#include "../hopper/Hopper.h"
#include <iostream>
#include <fstream>

Board::Board(){};
Board::~Board() {
    for (Bug* b : bug_vector) {
        delete b;
    }
    bug_vector.clear();
}
 void Board::readIn()
    {
        std::ifstream file("bugs.txt");
        char type, sep;
        int id, x, y, dir, health, hop;

        if (!file.is_open())
        {
            cout << "file not able to be opened!";
        }

        // Read the type character (c or h or v)
        while (file >> type)
        {
            file >> sep;         // eat first ';'
            file >> id >> sep;    // get ID and eat ';'
            file >> x >> sep;     // get X and eat ';'
            file >> y >> sep;     // get Y and eat ';'
            file >> dir >> sep;   // get Direction and eat ';'
            file >> health;       // get Health



            if (type == 'c')
            {
                bug_vector.push_back(new Crawler(id, x, y, static_cast< direction>(dir), health));
            }
            else if (type == 'h')
            {
                file >> sep >> hop; // get extra ';' and hopLength for Hoppers
                bug_vector.push_back(new Hopper(id, x, y, static_cast<direction>(dir), health, hop));
            }
            else if (type == 'v')
            {
                bug_vector.push_back(new VampireBug(id, x, y, static_cast<direction>(dir), health));
            }
        }
        file.close();
        cout << "initialised board with " << bug_vector.size() << " bugs!" << endl;
    }

    void Board::displayAllBugs() const
    {
        if (bug_vector.empty())
        {
            cout << "The board is empty. Please initialize first (Option 1)." << std::endl;
            return;
        }

        std::cout << "Displaying all bugs on the board:" << std::endl;
        for (Bug* b : bug_vector)
        {

            b->display();
        }
    }

void Board::findAndDisplayBug(int id) const
{
    bool exists = false;
    for (int i = 0; i < bug_vector.size(); i++)
    {
        if (id == bug_vector[i] -> getId())
        {
            exists = true;
            bug_vector[i] -> display();
            break;
        }
    }
    if (!exists)
    {
        cout << "Bug " << id << " not found in list!" << endl;
    }
}

void Board::tap()
{
    std::cout << "\n--- Tapping the Board! ---\n" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j].clear();
        }
    }


    for (int i = 0; i < bug_vector.size(); i++)
    {
        auto pos = bug_vector[i]->getPosition();
        if (bug_vector[i]->isAlive())
        {
            bug_vector[i]->move();

            auto pos = bug_vector[i]->getPosition();

            std::cout << "Bug " << bug_vector[i]->getId() << " moved to ";
            std::cout << "(" << pos.first << ", " << pos.second <<")" << std::endl;
            grid[pos.first][pos.second].push_back(bug_vector[i]);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // If more than one bug is in this bucket
            if (grid[i][j].size() > 1)
            {
                // Pair them off (0 vs 1, 2 vs 3...)
                for (size_t k = 0; k + 1 < grid[i][j].size(); k += 2)
                {
                    Bug* b1 = grid[i][j][k];
                    Bug* b2 = grid[i][j][k+1];

                    b1->drainHealth(b2);
                    b2->drainHealth(b1);

                    cout << "Fight! Between " << b1->getId() << " and " << b2->getId() << std::endl;
                    // Conduct 3 rounds of fighting
                    for (int round = 0; round < 3; round++)
                    {
                        // Random damage 0-5
                        b1->setHealth(b1->getHealth() - (rand() % 6));
                        b2->setHealth(b2->getHealth() - (rand() % 6));

                        cout << b1->getId() << "has: " << b1->getHealth() << " health remaining" << endl;
                        cout << b2->getId() << "has:  " << b2->getHealth() << " health remaining" << endl;
                        // End fight immediately if someone dies
                        if (!b1->isAlive() || !b2->isAlive())
                        {
                            std::cout << "the fight is over! \n";
                            break;
                        }
                    }
                }
            }
        }
    }
    int survivors = getAliveCount();
    if (survivors == 1)
    {
        for (int i = 0; i < bug_vector.size(); i++)
        {
            if (bug_vector[i]->isAlive())
            {
                cout << "A big congratulations to bug number " << bug_vector[i]->getId() << ", they are our lucky winner today! \n";
            }
        }
    }
}


    void Board::displayAllHistories() const
    {
        cout << "--- Bug Life History ---" << endl;
        for (int i = 0; i < bug_vector.size(); i++)
        {
            // Print ID and Type
            cout << bug_vector[i]->getId() << " ";

            // This checks if the bug is a Crawler or Hopper for the label
            if (dynamic_cast<Crawler*>(bug_vector[i])) cout << "Crawler ";
            else cout << "Hopper ";

            cout << "Path: ";

            bug_vector[i]->displayHistory();
            cout << endl;
        }
    }

    // Stage 6: The Grid Display
    void Board::displayCells()
    {
        // Loop through Rows (Y)
        for (int y = 0; y < 10; y++)
        {
            // Loop through Columns (X)
            for (int x = 0; x < 10; x++)
            {
                cout << "(" << x << "," << y << "): ";

                bool empty = true;
                // Loop through all bugs for this specific cell
                for (int k = 0; k < bug_vector.size(); k++)
                {
                    // Safety check
                    if (bug_vector[k] != nullptr)
                    {
                        std::pair<int, int> bugPos = bug_vector[k]->getPosition();

                        // Check if this bug (k) is at this cell (x, y)
                        if (x == bugPos.first && y == bugPos.second)
                        {
                            cout << "BUG! " << bug_vector[k]->getId() << " ";
                            empty = false;
                        }
                    }
                }

                if (empty) cout << "x";
                cout << " | "; // Separator for readability
            }
            cout << endl;
        }
    }

    // Stage 8: Save to file
    void Board::saveHistoryToFile(const std::string& filename)
    {
        std::ofstream outFile(filename);

        if (!outFile.is_open())
        {
            std::cout << "Error: Could not create " << filename << std::endl;
            return;
        }

        for (Bug* b : bug_vector)
        {
            // 1. Write basic info
            outFile << b->getId() << " ";

            // 2. Identify type for the file record
            if (dynamic_cast<Crawler*>(b)) outFile << "Crawler ";
            else outFile << "Hopper ";

            // 3. Write the path history
            b->displayHistory(outFile);

            // 4. Record if they were alive or dead at the end
            if (b->isAlive()) outFile << " (Alive)";
            else outFile << " (Dead)";

            outFile << std::endl;
        }

        outFile.close();
        std::cout << "All life histories saved to " << filename << std::endl;
    }
int Board::getAliveCount()
{
    int count = 0;
    for (int i = 0; i < bug_vector.size(); i++)
    {
        if (bug_vector[i]->isAlive())
        {
            count++;
        }
    }
    return count;
}