#include "algo.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <thread>

namespace kumar {
	using namespace std;

	char* reverse_string(char* str) {

		char* start = str;
		int len = strlen(str);

		for (int i = 0; i < len / 2; i++) {
			char temp = str[i];
			str[i] = str[len - i];
			str[len - i] = temp;
		}
		return str;
	}

	void sort_file_in_place(const char* filename) {
		fstream sort_file;
		sort_file.open(filename, ios::out | ios::in);

		vector <vector <int> > input_vect;
		string line;
		std::string delimiter = " ";
		int vect_index = 0;

		while (getline(cin, line)) {
			//store into vector of vectors
			//tokenise string 

			size_t pos = 0;
			int value = 0;
			int count = 0;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				string token = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				value = std::atoi(token.c_str());
				count++;
			}
			input_vect.resize(vect_index++, vector<int>(count));
		}

		//sort vector of vectors
		for (int i = 0; i < input_vect.size(); i++) {
			sort(input_vect[i].begin(), input_vect[i].end(), std::less<int>());
			//print the sorted vectors and alos verify the content 
			for (auto v : input_vect[i]) cout << v << " ";
		}

		//write back into the file
		//Todo

	}


	std::vector<std::string> split(const std::string & s, char c)
	{
		std::vector<std::string> splitted;

		std::string word;
		for (char ch : s)
		{
			if ((ch == c) && (!word.empty()))
			{
				splitted.push_back(word);
				word.clear();
			}
			else
				word += ch;
		}
		if (!word.empty())
			splitted.push_back(word);

		return splitted;
	}

	bool read_data(const std::string & file_path, std::vector<std::vector<int>> & data)
	{
		data.clear();

		std::ifstream in_s(file_path);
		if (!in_s)
			return false;

		std::string line;
		std::vector <int> row;
		while (std::getline(in_s, line))
		{
			if (!line.empty())
			{
				for (auto s : split(line, ' '))
					row.push_back(std::stoi(s));
				data.push_back(row);
				row.clear();
			}
		}

		in_s.close();
		return true;
	}

	bool write_data(const std::string & file_path, const std::vector<std::vector<int>> & data)
	{
		std::ofstream out_s(file_path);
		if (!out_s)
			return false;

		for (const auto& row : data)
		{
			for (size_t i = 0; i < row.size(); ++i)
			{
				if (i == 0)
					out_s << row[i];
				else
				{
					out_s << ((row[i] < 0) ? (" ") : ("  ")) << row[i];
				}
			}
			out_s << std::endl;
		}

		out_s.close();
		return true;
	}

	void sort_line(std::vector<int> & line)
	{
		std::sort(line.begin(), line.end(), [](const int& i, const int& j) {return i < j; });
	}

	void sort_data_lines(std::vector<std::vector<int>> & data)
	{
		std::vector<std::thread> thread_mem;

		for (auto& row : data)
		{
			thread_mem.push_back(std::thread(sort_line, std::ref(row)));
		}

		for (auto& t : thread_mem)
			t.join();
	}

	void sort_file_in_place_so

}; //namespace kumar
