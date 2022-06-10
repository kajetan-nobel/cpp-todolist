#include "AppController.h"
#include "../helpers/Clearscreen.h"
#include "../models/Task.h"
#include "../services/TaskDatabaseManager.h"
#include <iostream>
#include <cctype>

using namespace std;

// Helpers::clearscreen();

AppController::AppController() {
    this->taskManager = new TaskDatabaseManager();
}

void AppController::menuList() {
    cout << "Listuj to bitch" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Edit task" << endl;
    cout << "3. Toggle completion" << endl;
    cout << "4. Delete task" << endl;
    cout << "Q. Exit" << endl;
}

bool AppController::menuSelect() {
    char option;
    bool exit = false;

    cout << endl << "Please select option: ";
    cin >> option;

    switch ((int)toupper(option)) {
        // KEY "1"
        case 49:
            this->taskCreate();
            break;

        // KEY "2"
        case 50:
            this->taskEdit();
            break;

        // KEY "3"
        case 51:
            this->taskToggleCompletion();
            break;

        // KEY "4"
        case 52:
            this->taskDelete();
            break;

        // KEY "Q"
        case 81:
            exit = true;
            break;
        
        default:
            // do nothing, just catch.
            break;
    }

    return exit;
}

void AppController::initial() {
    bool exit;

    do {
        this->menuList();
        exit = this->menuSelect();
    } while (!exit);
}

void AppController::taskCreate() {
    string value;
    cout << "Task name: ";
    cin >> value;

    Task task(value);
    this->taskManager->create(task);
}

void AppController::taskEdit() {
    cout << "Edit" << endl;
}

void AppController::taskToggleCompletion() {
    cout << "Toggle" << endl;
    // Task task(value);
    // this->taskManager->update(task);
}

void AppController::taskDelete() {
    cout << "Delete" << endl;
}