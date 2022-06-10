#ifndef __APP_SERVICES_TASK_DATABASE_MANAGER__H
#define __APP_SERVICES_TASK_DATABASE_MANAGER__H

#include "../models/Task.h"
#include <string>
#include <vector>

class TaskDatabaseManager {
    public:
        std::vector<Task> paginate();
        void create(Task task);
        void update(Task task);
        void destroy(Task task);
    
    private: 
        static const std::string DB_FILE;
};

#endif