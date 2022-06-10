#include "Task.h"
#include <iostream>

class TaskDatabaseReader {
    public:
        Task *paginate(int perPage = 25) {
            Task* list;
            std::cout << "Paginate" << std::endl;
            return list;
        }

        void create() {
            std::cout << "Create" << std::endl;
        }

        void update() {
            std::cout << "Update" << std::endl;
        }

        void destroy() {
            std::cout << "Delete" << std::endl;
        }
};