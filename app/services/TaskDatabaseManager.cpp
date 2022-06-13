#include "TaskDatabaseManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

const string TaskDatabaseManager::DB_FILE = "database.csv";
const int TaskDatabaseManager::PER_PAGE = 10;

vector<Task> TaskDatabaseManager::paginate(int page) {
    fstream file = this->getFilestream(this->DB_FILE, ios_base::in);
    vector<Task> tasks;

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
    fstream file = this->getFilestream(
        this->DB_FILE,
        ios_base::in
    );
    
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
    fstream file = this->getFilestream(
        this->DB_FILE, 
        ios_base::app
    );

    file << task.toCsv() + "\n";
    file.close();
}

void TaskDatabaseManager::update(Task task) {
    fstream file = this->getFilestream(
        this->DB_FILE, 
        ios_base::in | ios_base::out
    );

    cout << "Update" << endl;
    cout << task.toCsv() << endl;
}

void TaskDatabaseManager::destroy(int id) {
    string tempFilename = "temp" + this->DB_FILE;
    
    // To avoid some duplication if something went wrong previously.
    remove(tempFilename.c_str());

    fstream file = this->getFilestream(this->DB_FILE, ios_base::out);
    fstream tempFile = this->getFilestream(tempFilename, ios_base::out);
    
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

fstream TaskDatabaseManager::getFilestream(
    string filePath,
    ios_base::openmode mode
) {
    fstream file;
    
    file.open(filePath, mode);

    if (!file.is_open()) {
        throw runtime_error("Unable to open " + filePath);
    }   

    return file;
}