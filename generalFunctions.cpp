#include <iostream>
#include <fstream>
#include "generalFunctions.h"
#include "users.h"
#include <vector>

std::vector<std::string> split(std::string str,std::string str2)
{
        std::vector <std::string > vp;
        std::string my_str = "";
        for (int i = 0; i <= str.size();++i)
        {
                bool b = true;
                for (int j = 0; j < str2.size(); ++j)
                {
                        if (str[i] == str2[j] || str[i] == '\0')
                        {
                                vp.push_back(my_str);
                                my_str.clear();
                                b = false;
                                break;
                        }
                }
                if (b == true)
                {
                        my_str.push_back(str[i]);
                }
        }
        std::vector<std::string> vk;
        for (int i = 0; i < vp.size(); ++i)
        {
                if (vp[i] == "")
                {
                        continue;
                }
                else {
                        vk.push_back(vp[i]);
                }
        }
        return vk;
}

std::vector<std::string> split_to_words(std::string input) {
	std::vector<std::string> result;
	unsigned int i{};
	unsigned int j{};
	result.push_back("");
	while (i < input.size()) {
		while (input[i] != ' ' && input[i] != '|' && input[i] != ',' && input[i] != '\0') {
			result[j].push_back(input[i]);
			++i;
			if (input[i] == ' ' || input[i] == ',') {
				++j;
				result.push_back("");
				break;
			}
		}
		if (input[i] == '\0') {
			return result;
		}
		++i;
	}
	return result;
}

void start() 
{
        std::cout << "Hello, welcome to Sona and Mariam's task management system!" << std::endl;
        std::cout << "Please, select the datas you want to work with." << std::endl;
        std::cout << "1.users\n2.tasks\n3.projects" << std::endl;
        int number_of_table{};
        while (true) {
                std::cin >> number_of_table;
                if (number_of_table != 1 && number_of_table != 2 && number_of_table != 3) {
                        std::cout << "Please, select the correnct number!" << std::endl;
                }
                else {
                        break;
                }
        }
        std::cout << "Please select one of the following instructions." << std::endl;
        std::cout << "1.insert\n2.select\n3.update\n4.delete" << std::endl;
        int number_of_instruction{};
        while (true) {
                std::cin >> number_of_instruction;
                if (number_of_instruction != 1 && number_of_instruction != 2 && number_of_instruction != 3 && number_of_instruction != 4) {
                        std::cout << "Please, select the correnct number!" << std::endl;
                }
                else {
                        break;
                }
        }
        if (number_of_table == 1) {
                Users user;
                if (number_of_instruction == 1) {
                        std::cout << "Please enter the datas of the user." << std::endl;
                        std::cout << "name = ";
                        std::string entered_name;
                        std::cin >> entered_name;
                        std::cout << "sureName = ";
                        std::string entered_sureName;
                        std::cin >> entered_sureName;
                        std::cout << "age = ";
                        int entered_age;
                        std::cin >> entered_age;
                        if (!file_is_empty("users.txt")) {
                                int lines_number = get_count_of_lines("users.txt");
                                std::string tmp = getline_from_a_file("users.txt", lines_number);
                                std::vector<std::string> a = split(tmp, "|");
                                user.setId(stoi(a[0]) + 1);
            }

            user.setName(entered_name);
            user.setSurName(entered_sureName);
            user.setAge(entered_age);
            user.insert();
                }
                else if (number_of_instruction == 2) {
                        std::cout << "Please write according to what you want to search user." <<std:: endl;
                        std::cout << "For example, 'I want to select with name and with age'" << std::endl;
                        std::string str;
                        std::cin.ignore();
                        getline(std::cin, str);
                        std::string newStr;
                        std::vector<std::string> vec = split(str, " ");
                        for(int i = 0; i < vec.size(); ++i){
                                newStr = newStr + vec[i];
                        }
                        std::cout << newStr;
                        if(newStr.find("name") != std::string::npos) { 
                                std::string name;
                                std::cout << "please enter user name which you want select users" << std::endl;
                                std::cin >> name;
                                user.select("users.txt", name);
                        }
                }
                else if (number_of_instruction == 3) {

                }
                else{

                }
        }
}

int get_count_of_lines(std::string filename) {
    std::string line;
    int count{};
    std::ifstream mFile(filename);
    if (mFile.is_open()) {
        while (mFile.peek() != EOF) {
            getline(mFile, line);
            count++;
        }
        mFile.close();
        return count;
    }
    std::cout << "Can't open the file!" << std::endl;
    return -1;
}

std::string getline_from_a_file(std::string filename, int line_number) {
    std::string line;
    const int number_of_lines = get_count_of_lines(filename);
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int lineno = 1; lineno <= number_of_lines; lineno++) {
            getline(file, line);
            if (lineno == line_number) {
                file.close();
                return line;
            }
        }
    }
    else std::cout << "Can not open the file";
    return "";
}

bool file_is_empty(std::string filename) {
    std::ifstream fin(filename);
    return fin.peek() == std::ifstream::traits_type::eof();
}



























