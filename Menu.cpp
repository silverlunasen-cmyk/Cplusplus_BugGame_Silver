//
// Created by Sysadmin on 30/04/2026.
//

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "board/Board.h"
#include "bugs/Bug.h"
#include "crawler/Crawler.h"
#include "hopper/Hopper.h"

using namespace std;

bool running = true;
int main()
{
    Board gameBoard;
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

        switch (input) {
        case 1:
            cout << "Initialising Bug board... \n";
            gameBoard.readIn();
            break;
        case 2:
            cout << "Displaying all Bugs:" << endl;
            gameBoard.displayAllBugs();
            break;
        case 3:
            {
                int id;
                cout << "Enter the id of the bug you would like to find";
                cin >> id;
                gameBoard.findAndDisplayBug(id);
                break;
            }
        case 4:
            cout << "Tap \n";
            gameBoard.tap();
            break;
        case 5:
            cout << "History is created by the victors \n";
            cout << "previous history";
            gameBoard.displayAllHistories();
            break;
        case 6:
            cout << "cells \n";
            gameBoard.displayCells();
            break;
        case 7:
            cout << "run forest, run \n";
            for(int i = 0; i < 5; i++)
            {
                gameBoard.tap();
            };
            break;
        case 8:
            {
                cout << "exit \n";
                gameBoard.saveHistoryToFile("history.txt");
                running = false;
                break;
                default:
                cout << "invalid input: please select 1-8 \n";
                break;
            }
        }
    }
}