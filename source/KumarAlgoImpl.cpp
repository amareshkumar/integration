#include "KumarAlgoImpl.h"
// check if a string is palindrome using a queue and a stack
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


/*
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * */
vector<vector<int>> KumarAlgoImpl::fourSum(vector<int>& nums, int target) {
	int sum = target;
	static int  count = 0;
	vector<vector<int>> result_Vect;
	vector<int> aux_vect(4);

	for (int i = 0; i < nums.size(); i++) {

		if (sum == nums[i] && count == 4) {
			result_Vect.push_back (aux_vect);
		}
		else if (sum == nums[i] && count != 4) {
			aux_vect.erase(aux_vect.begin(), aux_vect.end());
		}
		else {
			aux_vect.push_back(nums[i]);
			sum = sum - nums[i];
			count++;
			continue;
		}
	}
	return result_Vect;
}

