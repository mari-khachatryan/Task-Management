#include <iostream>
#include <fstream>
#include <string>
#include "tasks.h"


Task::Task(const std::string& newGmail,const std::string& newTitle, const std::string& newAuther, const std::string& newDescription, int newTaskId) 
:gmail{newGmail}
,title{newTitle}
,auther{newAuther}
,description{newDescription}
,taskId{newTaskId} {};

Task::~Task()
{
	std::cout << "Task add in data base";
}

void Task::setGmail(const std::string& newGmail){ gmail = newGmail; }
std::string Task::getGmail() { return gmail; };

void Task::setTitle(const std::string& newTitle) { title = newTitle; }
std::string Task::getTitle() {return title;}

void Task::setAuther(const std::string& newAuther) { auther = newAuther; }
std::string Task::getAuther() {return auther;}

void Task::setDescription(const std::string& newDescription) { description = newDescription; }
std::string Task::getDescription() { return description; } 

void Task::setTaskId(int newTaskId) { taskId = newTaskId; }
int Task::getTaskId() { return taskId; }

void Task::insert() {
    std::string data_to_be_inserted;
    std::string idStr = std::to_string(taskId);
    data_to_be_inserted = idStr + "|" + title + "|" + auther + "|" + description + "|" + gmail;

    std::ofstream fout;
    fout.open("tasks.txt", std::ofstream::app);
    if (!fout) {
        std::cout << "File not opened!";
    }
    else {
        fout << data_to_be_inserted << "\n";
    }
}


