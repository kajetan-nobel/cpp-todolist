#include "TaskDatabaseManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

const string TaskDatabaseManager::DB_FILE = "database.csv";
const int TaskDatabaseManager::PER_PAGE = 10;

vector<Task> TaskDatabaseManager::paginate(int page) {
    ifstream file;
    vector<Task> tasks;

    file.open(this->DB_FILE);

    if (!file || !file.is_open()) {
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

    file.close();

    return tasks;
}

Task TaskDatabaseManager::get(int id) {
    ifstream file;

    file.open(this->DB_FILE);

    if (!file.is_open()) {
        throw runtime_error("Unable to open " + this->DB_FILE);
    }

    string stream;
    int index = 0;

    while (getline(file, stream)) {
        if (index == id) {
            Task task = Task::fromCsv(to_string(id), stream);
            file.close();
            return task;
        }
        index++; 
    }

    file.close();

    throw invalid_argument("Task doesnt exists");
}

void TaskDatabaseManager::create(Task task) {
    ofstream file;
    file.open(this->DB_FILE, ios_base::app);

    if (!file.is_open()) {
        throw runtime_error("Unable to open " + this->DB_FILE);
    }

    file << task.toCsv() + "\n";
    file.close();
}

void TaskDatabaseManager::update(Task task) {
    // todo
}

void TaskDatabaseManager::destroy(int id) {
    ifstream file;
    ofstream tempFile; 
    string tempFilename = "temp" + this->DB_FILE;

    // To avoid some duplication if something went wrong previously.
    remove(tempFilename.c_str());

    file.open(this->DB_FILE);
    tempFile.open(tempFilename);

    if (!file.is_open()) {
        throw runtime_error("Unable to open " + this->DB_FILE);
    }

    if (!tempFile.is_open()) {
        throw runtime_error("Unable to open " + tempFilename);
    }

    string stream;
    int index = 0;

    while (getline(file, stream)) {
        if (index != id) {
            tempFile << stream << endl;
        }
        index++;
    }

    file.close();
    tempFile.close();

    remove(this->DB_FILE.c_str());
    rename(tempFilename.c_str(), this->DB_FILE.c_str());
}