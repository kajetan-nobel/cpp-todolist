#include "TaskDatabaseManager.h"
#include <iostream>
#include <fstream>

using namespace std;

const string TaskDatabaseManager::DB_FILE = "database.csv";

void TaskDatabaseManager::create(Task task) {
    ofstream file;
    file.open(this->DB_FILE, ios_base::app);
    file << task.toCsv() + "\n";
    file.close();
}

// Task* list;
// cout << "Paginate" << endl;
// return list;