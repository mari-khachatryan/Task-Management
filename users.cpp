#include <iostream>
#include <fstream>
#include <string>
#include "users.h"
#include <vector>
#include "generalFunctions.h"


Users::Users(const std::string& userName, const std::string& userSurname,const std::string& userGmail, const int& userAge, const int& userId)
    : name{ userName }
    , surName{ userSurname }
    , gmail{userGmail}
    , age{ userAge }
    , id{ userId }
{

};

void Users::insert() {
    std::string data_to_be_inserted;
    std::string ageStr = std::to_string(age);
    std::string idStr = std::to_string(id);
    data_to_be_inserted = idStr + "|" + name + "|" + surName + "|" + ageStr + "|" + gmail;

    std::ofstream fout;
    fout.open("users.txt", std::ofstream::app);
    if (!fout) {
        std::cout << "File not opened!";
    }
    else {
        fout << data_to_be_inserted << "\n";
    }
}

void Users::selectWithName(const std::string& path, const std::string& name) {
    std::vector<std::string> vecline;
    std::ifstream myfile(path);
    if (!myfile.is_open()) {
        std::cout << "Data base is unavailable, please check entered data" << std::endl;
        std::cout << "Program terminating.\n";
    }
    else {
        int i = 1;
        int count_of_lines = get_count_of_lines(path);
        while (count_of_lines)
        {
            vecline.push_back(getline_from_a_file(path, i));
            i++;
            --count_of_lines;
        }
        myfile.close();
    }

    int size = get_count_of_lines(path);

    for (int i = 0, j = 1; i < size; i++, j++) {
        std::vector<std::string> searched_data = split(vecline[i], "|");
        if (searched_data[1] == name) {
             std::cout << j << "." << searched_data[1] << " " << searched_data[2] 
             << " "  << searched_data[3] << " " << searched_data[4] << std::endl;
        }
    }
}



void Users::selectWithSername(const std::string& path, const std::string& sername) {
    std::vector<std::string> vecline;
    std::ifstream myfile(path);
    if (!myfile.is_open()) {
        std::cout << "Data base is unavailable, please check entered data" << std::endl;
        std::cout << "Program terminating.\n";
    }
    else {
        int i = 1;
        int count_of_lines = get_count_of_lines(path);
        while (count_of_lines)
        {
            vecline.push_back(getline_from_a_file(path, i));
            i++;
            --count_of_lines;
        }
        myfile.close();
    }

    int size = get_count_of_lines(path);

    for (int i = 0, j = 1; i < size; i++,j++) {
        std::vector<std::string> searched_data = split_to_words(vecline[i]);
        if (searched_data[2] == sername) {
             std::cout << j << "." << searched_data[1] << " " << searched_data[2] 
            << " "  << searched_data[3] << " " << searched_data[4] << std::endl;
        }
    }
}

void Users::update(const std::string& gmail, const std::string& path) {
    std::vector<std::string> vecline;
    std::ifstream myfile(path);
    if (!myfile.is_open()) {
        std::cout << "Data base is unavailable, please check entered data" << std::endl;
        std::cout << "Program terminating.\n";
    }
    else {
        int i = 1;
        int count_of_lines = get_count_of_lines(path);
        while (count_of_lines)
        {
            vecline.push_back(getline_from_a_file(path, i));
            i++;
            --count_of_lines;
        }
        myfile.close();
    }

    int size = get_count_of_lines(path);

    std::ofstream fout;
    fout.open("users.txt", std::ofstream::app);
    if (!fout) {
        std::cout << "File not opened!";
    }
    else {
        for (int i = 0; i < size; i++) {
        std::vector<std::string> searched_data = split_to_words(vecline[i]);
        if (stoi(searched_data[0]) != return_user_id(path, gmail)) {
            fout << vecline[i] << "\n";
        } else {
            std::string updateUser;
            std::string strId = std::to_string(return_user_id(path, gmail));
            std::cout << "Please enter new name = ";
            std::string name;
            std::cin >> name;
            std::cout << "Please enter new sername = ";
            std::string sername;
            std::cin >> sername;
            std::cout << "Please enter new age = ";
            int age;
            std::cin >> age;
            std::string strAge = std::to_string(age);
            updateUser = strId + "|" + name + "|" + sername + "|" + strAge + "|" + gmail;
            fout << updateUser << "\n";
        }
    }
    }

}


void Users::deleted(const std::string& gmail, const std::string& path) {
    std::vector<std::string> vecline;
    std::ifstream myfile(path);
    if (!myfile.is_open()) {
        std::cout << "Data base is unavailable, please check entered data" << std::endl;
        std::cout << "Program terminating.\n";
    }
    else {
        int i = 1;
        int count_of_lines = get_count_of_lines(path);
        while (count_of_lines)
        {
            vecline.push_back(getline_from_a_file(path, i));
            i++;
            --count_of_lines;
        }
        myfile.close();
    }
    int size = get_count_of_lines(path);

    for (int i = 0, j = 1; i < size; i++,j++) {
        Users user;
        std::vector<std::string> searched_data = split_to_words(vecline[i]);
        if (stoi(searched_data[0]) != return_user_id(path, gmail)) {
            std::ofstream fout;
            fout.open("users.txt", std::ofstream::app);
                if (!fout) {
                    throw  ("fatal error!");
                } else {
                    std::string name = searched_data[1];
                    std::string serName = searched_data[2];
                    std::string strAge = searched_data[3];
                    std::string mail = searched_data[4];

                    if (!file_is_empty("users.txt")) {
                            int lines_number = get_count_of_lines("users.txt");
                            std::string tmp = getline_from_a_file("users.txt", lines_number);
                            std::vector<std::string> a = split(tmp, "|");
                            user.setId(stoi(a[0]) + 1);
                    }

                    user.setName(name);
                    user.setSurName(serName);
                    user.setGmail(mail);
                    user.setAge(stoi(strAge));
                    user.insert();
                }
        } else {
            
        }
    }


}













