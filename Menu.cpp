//
// Created by Sysadmin on 30/04/2026.
//

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "bugs/Bug.h"
#include "crawler/Crawler.h"
#include "hopper/Hopper.h"

using namespace std;
void readIn(vector<Bug*>& bug_vector)
{
    std::ifstream file("bugs.txt");
    char type, sep;
    int id, x, y, dir, health, hop;

    if (!file.is_open())
    {
        cout << "file not able to be opened!";
    }

    // Read the type character (c or h)
    while (file >> type) {
        file >> sep;         // eat first ';'
        file >> id >> sep;    // get ID and eat ';'
        file >> x >> sep;     // get X and eat ';'
        file >> y >> sep;     // get Y and eat ';'
        file >> dir >> sep;   // get Direction and eat ';'
        file >> health;       // get Health



        if (type == 'c') {
            bug_vector.push_back(new Crawler(id, x, y, static_cast<enum direction>(dir), health));
        }
        else if (type == 'h') {
            file >> sep >> hop; // get extra ';' and hopLength for Hoppers
            bug_vector.push_back(new Hopper(id, x, y, static_cast<enum direction>(dir), health, hop));
        }
    }
    file.close();
}
bool running = true;
int main()
{
    vector<Bug*> bug_vector;
    while (running)
    {

        int input;
        cout << "----------------------------------------" << endl;
        cout << "              BUG BOARD MENU            " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Initialize Bug Board (load data from file)" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Display all Cells listing their Bugs" << endl;
        cout << "7. Run simulation (generates a Tap every second)" << endl;
        cout << "8. Exit (write Life History of all Bugs to file)" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Initialising Bug board";
            readIn(bug_vector);
            cout << bug_vector.size() << " bugs \n";
            break;
        case 2:
            cout << "Displaying all Bugs:" << endl;
            if (bug_vector.empty()) {
                cout << "No bugs on the board. Initialize first!" << endl;
            } else
            {
                for (Bug* b : bug_vector) {
                    // Polymorphism handles the different output for Crawler vs Hopper
                    b->display();
                }
            }
            break;
        case 3:
            {
                bool found = false;
                cout << "Enter the id of the bug you would like to find";
                int idNum;
                cin >> idNum;
                for (int i = 0; i < bug_vector.size(); i++)
                {
                    if (idNum == bug_vector[i] -> getId())
                    {
                        found = true;
                        bug_vector[i] -> display();
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Bug " << idNum << " not found in list!" << endl;
                }
                break;
            }
        case 4:
            cout << "Tap \n";
            for (int i = 0; i < bug_vector.size(); i++)
            {
                bug_vector[i] -> move();
            }
            break;
        case 5:
            cout << "History is created by the victors \n";
            cout << "previous history";
            cout << "--- Bug Life History ---" << endl;
            for (int i = 0; i < bug_vector.size(); i++) {
                // Print ID and Type
                cout << bug_vector[i]->getId() << " ";

                // This checks if the bug is a Crawler or Hopper for the label
                if (dynamic_cast<Crawler*>(bug_vector[i])) cout << "Crawler ";
                else cout << "Hopper ";

                cout << "Path: ";

                bug_vector[i]->displayHistory();
                cout << endl;
            }
            break;
        case 6:
            cout << "cells \n";
            break;
        case 7:
            cout << "run forest, run \n";
            break;
        case 8:
            {
                cout << "exit \n";
                ofstream Test("history.txt");
                if (Test.is_open()) {
                    for (int i = 0; i < bug_vector.size(); i++)
                    {
                        // Write the ID and Type first
                        Test << bug_vector[i]->getId() << " ";

                        // Write the path history to the file
                        bug_vector[i]->displayHistory();

                        // Add a newline after each bug
                        Test << endl;
                    }
                    Test.close();
                    cout << "History saved to history.txt!" << endl;
                }
            }
            running = false;
            break;
        default:
            cout << "invalid input: please select 1-8 \n";
            break;
        }
    }


}