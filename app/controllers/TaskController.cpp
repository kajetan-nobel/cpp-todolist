#include "TaskController.h"
#include "../services/TaskDatabaseManager.h"
#include "../helpers/Helpers.h"
#include "../helpers/Table.h"
#include "../models/Task.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <stdexcept>

using namespace std;

TaskController::TaskController() {
    this->taskManager = new TaskDatabaseManager();
    this->page = 1;
}

void TaskController::index() {
    vector<Task> tasks = this->taskManager->paginate(this->page);

    cout << Table::format("ID:", 10);
    cout << Table::format("What to do:", 40);
    cout << Table::format("Created At:", 22);
    cout << Table::format("Completed At:", 22);
    cout << endl;

    int index = 0;

    while(index < tasks.size()) {
        Task task = tasks[index];

        index++;
        cout << Table::format(task.getFormattedId(), 10);
        cout << Table::format(task.getFormattedValue(), 40);
        cout << Table::format(task.getFormattedCreatedAt(), 22);
        cout << Table::format(task.getFormattedCompletedAt(), 22);
        cout << endl;
    }

    cout << endl;
}

void TaskController::create() {
    string value;
    cout << "Task name: ";
    getline(std::cin, value);

    if (value.length() == 0) {
        throw invalid_argument("Value cant be empty.");
    }

    Task task(value);
    this->taskManager->create(task);
}

void TaskController::edit() {
    try {
        string id;
        string value;
        cout << "Please provide ID: " << endl;
        getline(std::cin, id);
        Task task = this->taskManager->get(stoi(id) - 1);
        cout << "Current value: " + task.getFormattedValue() << endl;
        cout << "New value: "; 
        getline(std::cin, value);
        task.setValue(value);
        this->taskManager->update(task);
    } catch(const invalid_argument& e) {
        throw invalid_argument("Task doesnt exists.");
    }
}

void TaskController::toggleCompletion() {
    try {    
        string id;
        cout << "Please provide ID: " << endl;
        getline(std::cin, id);
        Task task = this->taskManager->get(stoi(id) - 1);
        task.toggleCompletion();
        this->taskManager->update(task);
    } catch(const invalid_argument& e) {
        throw invalid_argument("Task doesnt exists.");
    }
}

void TaskController::destroy() {
    string id;
    cout << "Please provide ID: " << endl;
    getline(std::cin, id);
    this->taskManager->destroy(stoi(id) - 1);
}

void TaskController::pageUp() {
    this->page++;
}

void TaskController::pageDown() {
    if (this->page > 1) {
        this->page--;
    }
}