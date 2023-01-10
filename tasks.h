#include <iostream>
#include <string>

class Task {
    public:
        Task() : taskId (0) {};
        Task(const std::string& newGmail, const std::string& newTitle, const std::string& newAuther, const std::string& newDescription, int newTaskId);
        ~Task(); 

        void setGmail(const std::string& gmail);
        std::string getGmail();

        void setTitle(const std::string& title);  
        std::string getTitle();

        void setAuther(const std::string& userSureName);
        std::string getAuther();

        void setDescription(const std::string& description);
        std::string getDescription();

        void setTaskId(int taskId);
        int getTaskId();

        void insert();
        // void select(const std::string& path);
    private:
        std::string gmail;
        std::string title;
        std::string auther;
        std::string description;
        int taskId;
    };