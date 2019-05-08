#include "bit_manipulation.hpp"

int no_of_set_bits(int int_value) {
	vector <unsigned int> bit_vector;
	int value = int_value;
	do {
		unsigned int rem = value % 2;
		bit_vector.push_back(rem);
		value = value / 2;

	} while (value != 1);
	bit_vector.push_back(value);
	reverse(begin(bit_vector), end(bit_vector)); //although it is not needed for the purpose

	int count = 0;
	for (int i = 0; i < bit_vector.size(); ++i) {
		if (int_value & (1 << i)) {
			count++;
		}
	}
	return count;
}