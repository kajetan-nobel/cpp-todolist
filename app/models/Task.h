#ifndef __APP_MODELS_TASK__H
#define __APP_MODELS_TASK__H

#include <string>
#include <ctime>

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

        std::string getFormattedId();
        std::string getFormattedValue();
        std::string getFormattedCreatedAt();
        std::string getFormattedCompletedAt();

        void setValue(std::string value);
        void setCreatedAt(std::string value);
        void setCompletedAt(std::string value);

        std::string toCsv();
        
        Task static fromCsv(
            std::string id, 
            std::string data
        );
};

#endif