#ifndef __APP_SERVICES_TASK_DATABASE_MANAGER__H
#define __APP_SERVICES_TASK_DATABASE_MANAGER__H

#include "../models/Task.h"
#include <string>

class TaskDatabaseManager {
    public:
        // Task *paginate(int perPage = 25);
        void create(Task task);
        void update();
        void destroy(Task task);
    
    private: 
        static const std::string DB_FILE;
};

#endif