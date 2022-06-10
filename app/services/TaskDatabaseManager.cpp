#include "TaskDatabaseManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string TaskDatabaseManager::DB_FILE = "database.csv";

vector<Task> TaskDatabaseManager::paginate() {
    ifstream file;
    vector<Task> tasks;

    file.open(this->DB_FILE);

    if (!file) {
        cerr << "Error: file could not be opened" << endl;
        return tasks;
    }

    string stream;
    int index = 0;

    while (!file.eof()) {
        getline(file, stream);

        if (stream != "") {
            tasks.insert(
                tasks.begin() + index, 
                Task::fromCsv(to_string(index + 1), stream)
            );
        }

        index++;
    }

    return tasks;
}

void TaskDatabaseManager::create(Task task) {
    ofstream file;
    file.open(this->DB_FILE, ios_base::app);
    file << task.toCsv() + "\n";
    file.close();
}

void TaskDatabaseManager::update(Task task) {
    // todo
}