#include "algo.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>


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

}; //namespace kumar
