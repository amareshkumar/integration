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

bool check_prime (int n) {
	if (n == 2) return true;

	//no need to take care less than 2
	for (int i = 2; i*i <= n; i++) {
		if (n % i ==0) {
			return false;
		}
	}
	return true;
}

vector<int> return_prime_sum (vector<int> &prime_v, int sum) {
	vector <int> result(2);
	static int first = 0;
	static int second = 0;

	for (int i = 0; i < prime_v.size(); i++){
		first = prime_v[i];
		second = 0;
		bool found = false;
		for (int j = i+1; j < prime_v.size(); j++){
			if (prime_v[j] == (sum-first)) {
				second = prime_v[j];//got first pair
				found = true;
				break;
			}
		} //inner loop
		if (found) break;
	}

	result[0] = first;
	result[1] = second;

	return result;
}

vector<int> KumarAlgoImpl::prime_sum (int num) {

	vector<int> prime_list;

	for (int i=2; i < num; i++){
		if (check_prime(i)) {
			prime_list.push_back(i);
		}
	}

	return return_prime_sum (prime_list, num);
}
