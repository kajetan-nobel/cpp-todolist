#ifndef __APP_MODELS_TASK__H
#define __APP_MODELS_TASK__H

#include <string>

class Task {
    private:
        std::string id;
        std::string value;
        std::string created_at;
        std::string completed_at;

    public:
        Task(
            std::string value
        );

        Task(
            std::string id,
            std::string value,
            std::string created_at,
            std::string completed_at
        );

        std::string getId();
        std::string getValue();
        std::string getCreatedAt();
        std::string getCompletedAt();

        std::string toCsv();
        
        Task static fromCsv(
            std::string id, 
            std::string data
        );

        void dump();
};

#endif