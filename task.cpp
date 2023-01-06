#include <iostream>
#include <string>
#include "tasks.h"


Task::Task(const std::string& newTitle, const std::string& newAuther, const std::string newDescription, int newTaskId) 
:title{newTitle}
,auther{newAuther}
,description{newDescription}
,taskId{newTaskId}{};

Task::~Task()
{
	std::cout << "Task add in data base";
}

void Task::setTitle(const std::string& newTitle) {
	title = newTitle;
}

std::string Task::getTitle() {
	return title;
}

void Task::setAuther(const std::string& newAuther) {
	auther = newAuther;
}

std::string Task::getAuther() {
	return auther;
}

void Task::setDescription(int newDescription) {
	description = newDescription;
}

std::string Task::getDescription() {
	return description;
}
void Task::setTaskId() {
	taskId = newTaskId;
}

int Task::gettaskId() {
	return taskId;
}


