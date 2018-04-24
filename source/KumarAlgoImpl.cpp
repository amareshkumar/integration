#include "KumarAlgoImpl.h"
// check if a string is palindrome using a queue and stack
bool KumarAlgoImpl::isPalindrome(const std::string str) {

	for (int i=0; i<str.length(); i++) {
		pushCharacter (str[i]);
		enqueueCharacter(str[i]);
	}

	bool is_palindrome = true;

	for (int i =0 ; i < str.length() / 2; i++) {
		if (popCharacter() != dequeueCharacter()){
			is_palindrome = false;

			break;
		}
	}

	return is_palindrome;
}
