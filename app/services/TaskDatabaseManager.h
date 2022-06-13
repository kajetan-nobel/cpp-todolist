#ifndef __APP_SERVICES_TASK_DATABASE_MANAGER__H
#define __APP_SERVICES_TASK_DATABASE_MANAGER__H

#include "../models/Task.h"
#include <string>
#include <vector>
#include <fstream>

class TaskDatabaseManager {
    public:
        std::vector<Task> paginate(int page);
        Task get(int id);
        void create(Task task);
        void update(Task task);
        void destroy(int id);
    
    private: 
        static const int PER_PAGE;
        static const std::string DB_FILE;

        std::fstream getFilestream(
            std::string fileName,
            std::ios_base::openmode mode
        );

        std::fstream getTempFilestream(
            std::string fileName,
            std::ios_base::openmode mode
        );
};

#endif