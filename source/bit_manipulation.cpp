#include "bit_manipulation.hpp"

/*
client code:
//calculate no of set bits in an integer
int int_value = 0;
cout << "enter value: ";
cin >> int_value;
//no_of_set_bits(int_value);

cout << "No. of set bits in " << int_value << " is: " << no_of_set_bits(int_value) << endl;
To do: optimize the solution
*/
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