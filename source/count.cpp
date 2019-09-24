#include "count.h"

namespace kumar {

	template <typename T>
	int count(std::vector <T> input, T value) {
		int count = 0;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == value) {
				count++;
			}
		}

		return count;
	}
};
