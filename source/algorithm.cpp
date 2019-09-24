#include "algorithm.h"

namespace kumar {

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

}; //namespace kumar
