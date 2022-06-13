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

using namespace std;

TaskController::TaskController() {
    this->taskManager = new TaskDatabaseManager();
    this->page = 1;
}

void TaskController::index() {
    vector<Task> tasks = this->taskManager->paginate(this->page);

    cout << Table::format("ID:", 15);
    cout << Table::format("What to do:", 50);
    cout << Table::format("Created At:", 20);
    cout << Table::format("Completed At:", 20);
    cout << endl;

    int index = 0;

    while(index < tasks.size()) {
        Task task = tasks[index];

        index++;
        cout << Table::format(task.getFormattedId(), 10);
        cout << Table::format(task.getFormattedValue(), 50);
        cout << Table::format(task.getFormattedCreatedAt(), 20);
        cout << Table::format(task.getFormattedCompletedAt(), 20);
        cout << endl;
    }

    cout << endl;
}

void TaskController::create() {
    string value;
    cout << "Task name: ";
    getline(std::cin, value);

    Task task(value);
    this->taskManager->create(task);
}

void TaskController::edit() {
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
}

void TaskController::toggleCompletion() {
    cout << "Toggle" << endl;
    // Task task(value);
    // this->taskManager->update(task);
}

void TaskController::destroy() {
    string value;
    cout << "Please provide ID: " << endl;
    getline(std::cin, value);
    this->taskManager->destroy(stoi(value) - 1);
}

void TaskController::pageUp() {
    this->page++;
}

void TaskController::pageDown() {
    if (this->page > 1) {
        this->page--;
    }
}