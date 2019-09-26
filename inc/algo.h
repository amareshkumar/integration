#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <algorithm>

namespace kumar {

	extern "C" char* reverse_string(char* str);
	extern "C" void sort_file_in_place(const char* filename);
};// namespace kumar