#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <algorithm>

namespace kumar {

	char* reverse_string(char* str);
	void sort_file_in_place(const char* filename);

	//stackoverflow help
	void sort_data_lines(std::vector<std::vector<int>>& data);
	bool write_data(const std::string& file_path, const std::vector<std::vector<int>>& data);
	bool read_data(const std::string& file_path, std::vector<std::vector<int>>& data);
};// namespace kumar