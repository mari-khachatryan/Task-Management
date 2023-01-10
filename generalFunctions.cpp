#include <iostream>
#include <fstream>
#include "generalFunctions.h"
#include "users.h"
#include "tasks.h"
#include "projects.h"
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
			if (input[i] == ' ' ||  input[i] == ','  || input[i] == '|' ) {
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
        switch (number_of_table)
        {
        case 1:
                work_with_users();
                break;
        case 2:
                work_with_tasks();
                break;
        case 3:
                work_with_projects();
                break;
        
        default:
                break;
        }
        
}
void work_with_users() {
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
          Users user;
                if (number_of_instruction == 1) {
                        std::cout << "Please enter the datas of the user." << std::endl;
                        std::cout << "name = ";
                        std::string entered_name;
                        std::cin >> entered_name;
                        std::cout << "sureName = ";
                        std::string entered_sureName;
                        std::cin >> entered_sureName;
                        std::cout << "gmail = ";
                        std::string gmail;
                        while (true)
                        {
                                std::cin >> gmail;
                                if(!check_gmail("users.txt", gmail) || gmail.find("@gmail.com") == std::string::npos || gmail.length() < 11) {
                                        std::cout << "A user with such gmail already exists, the gmail must be unique or incorrect input!" << std::endl;
                                } else {
                                        break;
                                }
                        }
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
            user.setGmail(gmail);
            user.setAge(entered_age);
            user.insert();
                }
                else if (number_of_instruction == 2) {
                        std::cout << "Please write according to what you want to search user." <<std:: endl;
                        std::cout << "For example, 'I want to select with firstname, lastname and with age'" << std::endl;
                        std::string str;
                        std::cin.ignore();
                        getline(std::cin, str);
                        std::string newStr;
                        std::vector<std::string> vec = split(str, " ");
                        for(int i = 0; i < vec.size(); ++i){
                                newStr = newStr + vec[i];
                        }
                        std::cout << newStr;
                        if(newStr.find("firstname") != std::string::npos && newStr.find("lasttname") == std::string::npos &&
                        newStr.find("age") == std::string::npos) { 
                                std::string name;
                                std::cout << "please enter user name which you want select users" << std::endl;
                                std::cin >> name;
                                user.selectWithName("users.txt", name);
                        }  else if (newStr.find("firstname") == std::string::npos && newStr.find("lastname") != std::string::npos &&
                                newStr.find("age") == std::string::npos) { 
                                std::string sername;
                                std::cout << "please enter user sername which you want select users" << std::endl;
                                std::cin >> sername;
                                user.selectWithSername("users.txt", sername);
                        } else if (newStr.find("firstname") == std::string::npos && newStr.find("lastname") == std::string::npos &&
                                newStr.find("age") != std::string::npos) {
                                int age;
                                std::cout << "please enter user age which you want select users" << std::endl;
                                std::cin >> age;
                                user.selectWithAge("users.txt", age);
                        }  else if (newStr.find("firstname") != std::string::npos && newStr.find("lastname") != std::string::npos &&
                                newStr.find("age") == std::string::npos) {
                                std::string name;
                                std::string sername;
                                std::cout << "please enter user firstname and lastname which you want select users" << std::endl;
                                std::cout << "name = ";
                                std::cin >> name;
                                std::cout << "surname = ";
                                std::cin >> sername;
                                //user.selectWithNameSurname("users.txt", name, sername);
                        }else if (newStr.find("firstname") != std::string::npos && newStr.find("lastname") == std::string::npos &&
                                newStr.find("age") != std::string::npos) {
                                std::string name;
                                int age;
                                std::cout << "please enter user firstname and age which you want select users" << std::endl;
                                std::cout << "name = ";
                                std::cin >> name;
                                std::cout << "age = ";
                                std::cin >> age;
                                //user.selectWithNameAge("users.txt", name, age);
                        }else if (newStr.find("firstname") == std::string::npos && newStr.find("lastname") != std::string::npos &&
                                newStr.find("age") != std::string::npos) {
                                std::string surname;
                                int age;
                                std::cout << "please enter lastname and age which you want select users" << std::endl;
                                std::cout << "surname = ";
                                std::cin >> surname;
                                std::cout << "age = ";
                                std::cin >> age;
                                //user.selectWithSurnameAge("users.txt", name, age);
                        }
                         else {
                                std::cout << "Please enter corect according of sername! " << std::endl;
                        }
                }
                else if (number_of_instruction == 3) {
                        std::cout << "Please enter the gmail, according to which user data should be found and changed." << std::endl;
                        std::string gmail;
                        while (true) {
                                std::cin >> gmail;
                                if(check_gmail("users.txt", gmail)) {
                                        std::cout << "Please, select the correnct gmail!" << std::endl;
                                } else {
                                        break;
                                }
                        }
                        rename("users.txt", "users1.txt");
                        user.update(gmail, "users1.txt");
                        remove("users1.txt");
                }
                else{
                        std::cout << "Please enter the gmail, according to which user data should be deleted." << std::endl;
                        std::string gmail;
                        while (true) {
                                std::cin >> gmail;
                                if(check_gmail("users.txt", gmail)) {
                                        std::cout << "Please, select the correnct gmail!" << std::endl;
                                } else {
                                        break;
                                }
                        }
                        
                        rename("users.txt", "users2.txt");
                        user.deleted(gmail, "users2.txt");
                        remove("users2.txt");
                }
}

void work_with_tasks() {
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

        Task task;
                if (number_of_instruction == 1) {
                        std::cout << "Please enter our gmail to make sure that the given user is registered in database" << std::endl;
                        std::cout << "gmail = ";
                        std::string gmail;
                         while (true)
                        {
                                std::cin >> gmail;
                                if(check_gmail("users.txt", gmail)) {
                                        std::cout << "A user with such gmail does not exists, please register!" << std::endl;
                                        work_with_users();
                                } else {
                                        break;
                                }
                        }
                        std::cout << "title = ";
                        std::string entered_title;
                        std::cin >> entered_title;
                        std::cout << "auther (name/sername)= ";
                        std::string entered_auther;
                        std::cin >> entered_auther;
                        std::cout << "description= ";
                        std::string entered_description;
                        std::cin >> entered_description;
                       

                        if (!file_is_empty("tasks.txt")) {
                                int lines_number = get_count_of_lines("tasks.txt");
                                std::string tmp = getline_from_a_file("tasks.txt", lines_number);
                                std::vector<std::string> a = split(tmp, "|");
                                task.setTaskId(stoi(a[0]) + 1);
                        }

            task.setGmail(gmail);
            task.setTitle(entered_title);
            task.setAuther(entered_auther);
            task.setDescription(entered_description);
            task.insert();
                }
                else if (number_of_instruction == 2) {
                      
                }
                else if (number_of_instruction == 3) {
                      
                }
                else { 
                       
                }

}

void work_with_projects() {
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

// std::vector<std::string> get_all_lines(std::string path) {
//         std::vector<std::string>* vecline;
//         std::ifstream myfile(path);
//         if (myfile.is_open()) {
//         int i = 0;
//         int count_of_lines = get_count_of_lines(path);
//         while (count_of_lines)
//         {
//                 vecline->push_back(getline_from_a_file(path, i));
//                 i++;
//                 --count_of_lines;
//         }
//         myfile.close();
//         }
//         return *vecline;
// }

bool file_is_empty(std::string filename) {
        std::ifstream fin(filename);
        return fin.peek() == std::ifstream::traits_type::eof();
}

int return_user_id(std::string path, std::string gmail) {
        std::vector<std::string> vecline;
        std::ifstream myfile(path);
        if (myfile.is_open()) {
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

        for (int i = 0; i < size; i++) {
                std::vector<std::string> searched_data = split_to_words(vecline[i]);
                if (searched_data[4] == gmail) {
                        return stoi(searched_data[0]);
                }
        }
 return 0;
        
}

bool check_gmail(std::string path, std::string gmail) {
        std::vector<std::string> vecline;
        std::string line{};
        std::ifstream myfile(path);
        if (myfile.is_open()) {
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

        for (int i = 0; i < size; i++) {
                std::vector<std::string> searched_data = split(vecline[i], "|");
                if (searched_data[4] == gmail) {
                        return false;
                }
        }

        return true;
}



























