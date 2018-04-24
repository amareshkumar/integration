#include "integrationClient.h"
#include <string>
#include <iostream>

using namespace std;

int main () {

	string input_str;
	std::cout << "Enter string to check if it is palindrome: ";
	getline (cin, input_str);
	KumarAlgoImpl kumaralgoimpl;

    if ( kumaralgoimpl.isPalindrome (input_str)) {
    	cout << "the input string is palindrome" << endl;
    } else {
    	cout << "the input string isn't palindrome" << endl;
    }

	return 0;
}
