#ifndef __APP_CONTROLLER__H
#define __APP_CONTROLLER__H

#include "TaskController.h"

class AppController {
    private:
        TaskController *taskController;
        void menuList();
        bool menuSelect();

    public:
        AppController();
        void initial();
};

#endif