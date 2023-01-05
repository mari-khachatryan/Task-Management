#include <iostream>
#include "projects.h"


Project::Project (const std::string& newprojectName, const std::string& newProjectManagerName, const std::string& newProjectManagerSName, int newProjectId)
: projectName{newprojectName}
, projectManagerName{newProjectManagerName}
, projectManagerSName{newProjectManagerSName}
, projectId{newProjectId} {};

Project::~Project() {
	std::cout << "Project data saved in data-base";
}

void Project::setProjectName(const std::string& newProjectName) {
	projectName = newProjectName;
}

std::string Project::getProjectName() {
	return projectName;
}

void Project::setprojectManagerName(const std::string& newProjectManagerName) {
	projectManagerName = newProjectManagerName;
}

std::string Project::getprojectManagerName() {
	return projectManagerName;
}

void Project::setprojectManagerSName(const std::string& newProjectManagerSName) {
	projectManagerSName = newProjectManagerSName;
}

std::string Project::getprojectManagerSName() {
	return projectManagerSName;
}

void setProjectId (int newProjectId) {
	projectId = newProjectId;
}

int Project::getProjectId() {
	return projectId;
}

