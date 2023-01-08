#include <iostream>
#include <string>

class Task {
    public:
        Task() {};
        Task(const std::string& newTitle, const std::string& newAuther, const std::string& newDescription, int newTaskId);
        ~Task(); 

        void setTitle(const std::string& title);  
        std::string getTitle();

        void setAuther(const std::string& userSureName);
        std::string getAuther();

        void setDescription(int description);
        std::string getDescription();

        void setTaskId(int taskId);
        int getTaskId();

        // void insert(const std::string& path);
        // void select(const std::string& path);
    private:
        std::string title;
        std::string auther;
        std::string description;
        int taskId;
    };