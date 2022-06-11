#include "TaskDatabaseManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string TaskDatabaseManager::DB_FILE = "database.csv";
const int TaskDatabaseManager::PER_PAGE = 10;

vector<Task> TaskDatabaseManager::paginate(int page) {
    ifstream file;
    vector<Task> tasks;

    file.open(this->DB_FILE);

    if (!file) {
        return tasks;
    }

    string stream;
    int index = 0;
    int toGet = 0;
    int toIgnore = (page - 1) * this->PER_PAGE;

    while (getline(file, stream)) {
        index++; 
        
        if (toIgnore > 0) {
            --toIgnore;
            continue;
        }

        if (toGet == this->PER_PAGE) {
            break;
        }

        if (stream != "") {
            tasks.insert(
                tasks.begin() + toGet, 
                Task::fromCsv(to_string(index - 1), stream)
            );
            toGet++;
        }
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

void TaskDatabaseManager::destroy(int id) {
    ofstream file;
    file.open(this->DB_FILE);
    // line.replace(line.find(deleteline),deleteline.length(),"");
}