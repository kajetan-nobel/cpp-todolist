#include "Task.h"
#include "../helpers/Csv.h"
#include <sstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Task::Task(string value) {
    long int now = static_cast<long int>(time(NULL));

    this->id = "";
    this->value = value;
    this->created_at = to_string(now);
    this->completed_at = "";
}

Task::Task(
    string id,
    string value,
    string created_at,
    string completed_at
) {
    this->id = id;
    this->value = value;
    this->created_at = created_at;
    this->completed_at = completed_at;
}

void Task::dump() {
    cout << endl;
    cout << "---------" << endl;
    cout << "Value: " << this->value << endl;
    cout << "Created At: " << this->created_at << endl;
    cout << "Completed At: " << this->completed_at << endl;
    cout << "---------" << endl;
    cout << endl;
}

string Task::toCsv() {
    string tmp;
    tmp += this->value + ",";
    tmp += this->created_at + ",";
    tmp += this->completed_at;
    return tmp;
}

Task Task::fromCsv(string id, string data) {
    vector<string> row = CSV::read_row(data, ',');    
    
    Task task(
        id,
        row[0],
        row[1],
        row[2]
    );

    return task;
}

string Task::getId() {
    return this->id;
}

string Task::getValue() {
    return this->value;
}

string Task::getCreatedAt() {
    return this->created_at;
}

string Task::getCompletedAt() {
    return this->completed_at;
}