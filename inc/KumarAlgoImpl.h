#pragma once
#ifndef KUMARALGOIMPL_H_
#define KUMARALGOIMPL_H_


#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class KumarAlgoImpl {
    //Write your code here
public:
	// check if a string is palindrome using a queue and stack
	bool isPalindrome(const std::string str);
	vector<vector<int>> fourSum(vector<int>& nums, int target);

private:
    stack<char> m_stack;
    queue<char> m_queue;

    void pushCharacter (const char ch) {
       m_stack.push (ch);
    }

    char popCharacter (){
        return m_stack.top();
    }

    void enqueueCharacter (const char ch){
        m_queue.push(ch);
    }

    char dequeueCharacter () {
        return m_queue.front();
    }
};


#endif  // KUMARALGOIMPL_H_
