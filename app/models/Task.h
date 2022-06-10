#ifndef __APP_MODELS_TASK__H
#define __APP_MODELS_TASK__H

#include <string>

class Task {
    private:
        std::string value;
        std::string created_at;
        std::string completed_at;

    public:
        Task(
            std::string value
        );

        Task(
            std::string value,
            std::string created_at,
            std::string completed_at
        );

        std::string toCsv();
        void dump();
};

#endif