#include "AppController.h"
#include "../helpers/Helpers.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

using namespace std;

AppController::AppController() {
    this->taskController = new TaskController();
}

void AppController::menuList() {
    this->taskController->index();
    cout << "1. Add task" << endl;
    cout << "2. Edit task" << endl;
    cout << "3. Toggle completion" << endl;
    cout << "4. Delete task" << endl;
    cout << "A. Previous Page" << endl;
    cout << "S. Next Page" << endl;
    cout << "Q. Exit" << endl;
}

bool AppController::menuSelect() {
    string option;
    bool exit = false;

    cout << endl << "Please select option: ";
    getline(cin, option);

    Helpers::clearscreen();

    if (option == "1") { 
        this->taskController->create();
    } else if (option == "2") {
        this->taskController->edit();
    } else if (option == "3") {
        this->taskController->toggleCompletion();
    } else if (option == "4") {
        this->taskController->destroy();
    } else if (option == "A" || option == "a") {
        this->taskController->pageDown();
    } else if (option == "S" || option == "s") {
        this->taskController->pageUp();
    } else if (option == "Q" || option == "q") {
        exit = true;
    }

    Helpers::clearscreen();

    return exit;
}

void AppController::initial() {
    bool exit;

    Helpers::clearscreen();

    do {
        try {
            this->menuList();
            exit = this->menuSelect();
        } catch(const invalid_argument& e) {
            std::cerr << e.what() << endl;
        } catch(const runtime_error& e) {
            std::cerr << e.what() << endl;
        }
    } while (!exit);
}