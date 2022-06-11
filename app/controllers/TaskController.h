#ifndef __TASK_CONTROLLER__H
#define __TASK_CONTROLLER__H

#include "../services/TaskDatabaseManager.h"

class TaskController {
    private:
        TaskDatabaseManager *taskManager;
        int page;

    public:
        TaskController();
        void index();
        void create();
        void edit();
        void toggleCompletion();
        void destroy();

        void pageUp();
        void pageDown();
};

#endif