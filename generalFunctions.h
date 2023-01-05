#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string, std::string);
std::vector<std::string> split_to_words(std::string input);
void start();
int get_count_of_lines(std::string filename);
std::string getline_from_a_file(std::string filename, int line_number);
bool file_is_empty(std::string filename);

