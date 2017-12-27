#pragma once 
#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include "my_project_app.h"
using namespace std; 
class programming_questions {
public:
	string static Reverse(string str);
	string& reverse(std::string &st, int init, int final);
	string& reverse_word_wise(std::string &str);
	int max_diff_arr_index (vector <int> int_array);
};


#endif //PROGRAMMING_H
