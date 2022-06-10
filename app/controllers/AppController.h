#ifndef __APP_CONTROLLER__H
#define __APP_CONTROLLER__H

#include "../services/TaskDatabaseManager.h"

class AppController {
    private:
        TaskDatabaseManager *taskManager;

        void menuList();
        bool menuSelect();

        void taskCreate();
        void taskEdit();
        void taskToggleCompletion();
        void taskDelete();

    public:
        AppController();
        void initial();
};

#endif