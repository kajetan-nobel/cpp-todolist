#include "Task.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Task::Task(string value) {
    long int now = static_cast<long int>(time(NULL));

    this->value = value;
    this->created_at = to_string(now);
    this->completed_at = "";
}

Task::Task(
    string value,
    string created_at,
    string completed_at
) {
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