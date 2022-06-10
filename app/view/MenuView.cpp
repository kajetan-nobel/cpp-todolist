#include "MenuView.h"
#include "../helpers/Clearscreen.h"
#include <iostream>
#include <cctype>

using namespace std;

void MenuView::list() {
    cout << "Listuj to bitch" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Edit task" << endl;
    cout << "3. Toggle completion" << endl;
    cout << "4. Delete task" << endl;
    cout << "Q. Exit" << endl;
}

bool MenuView::select() {
    char option;
    bool correct = false;

    cout << endl << "Please select option: ";
    cin >> option;

    switch ((int)toupper(option)) {
        case 1:
            cout << "Add" << endl;
            correct = true;
            break;

        case 2:
            cout << "Edit" << endl;
            correct = true;
            break;

        case 3:
            cout << "Toggle" << endl;
            correct = true;
            break;

        case 4:
            cout << "Delete" << endl;
            correct = true;
            break;

        // Q
        case 81:
            cout << "Exit" << endl;
            correct = true;
            break;
        
        default:
            // do nothing, just catch.
            break;
    }

    return correct;
}

void MenuView::initial() {
    bool correct;

    do {
        this->list();
        correct = this->select();
        Helpers::clearscreen();
    } while (!correct);
}