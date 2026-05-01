//
// Created by Sysadmin on 30/04/2026.
//
#include <iostream>

#include <cmath>
#include <vector>
#include "\bugs\Bug.h"
using namespace std;

bool run = true;


int main()
{
    while (run)
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
                break;
            case 2:
                cout << "Displaying all Bugs (fix the code!)";
                break;
            case 3:
                cout << "Find a Bug (given an id)";
                break;
            case 4:
                cout << "Tap";
                break;
            case 5:
                cout << "History is created by the victors";
                break;
            case 6:
                cout << "cells";
                break;
            case 7:
                cout << "run forest, run";
                break;
            case 8:
                cout << "goodbye!";
                run = false;
                break;
            default:
                cout << "invalid input: please select 1-8";
                break;
        }
    }
}
int displayAll()
{
    vector<Bug*> bug_vector;
}

