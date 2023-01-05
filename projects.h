#include <iostream>
#include <string>


class Project {
     public:
        Project();
        Project(const std::string& newprojectName, const std::string& projectManagerName, const std::string& projectManagerSName, int newProjectId);
        ~Project();
        
        void setProjectName(const std::string& projectName);    
        std::string getProjectName();

        void setprojectManagerName(const std::string& projectManagerName);
        std::string getprojectManagerName();

        void setprojectManagerSName(const std::string& projectManagerSName);
        std::string getprojectManagerSName();

        void setProjectId(int projectId);
        int getProjectId();

        // void insert(const std::string& path);
        // void select(const std::string& path);

    private:
        std::string projectName;
        std::string projectManagerName;
        std::string projectManagerSName; 
        int projectId;
};