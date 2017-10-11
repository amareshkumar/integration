/* 
 * File:   MyString.hpp
 * Author: amakumar
 *
 * Created on July 27, 2015, 1:53 PM
 */

#ifndef MYSTRING_HPP
#define	MYSTRING_HPP

#include "my_project_app.h"

class MyString {
public:
    MyString();
    ~MyString();
    MyString (const char* st);
    MyString (const MyString & str);
    MyString& operator= (const MyString & str);
    MyString& operator+ (MyString& str) const;
    int GetLength (MyString& str) const;
    char* GetMyString ();
    void SetMyString (const char* st);
    int Get_No_of_MyString_Obj() const; 
    static char* MyStringReverse (char *str2Reverse); 
    char* myAppend (char* strToAppend);
	//imported from CodingTest.h
	bool check_palindrome_sent(string sent);
	bool check_anagram_words (string first, string second);
	const char* get_desc () const {
		return desc;
	}

	const char& operator[] (const int index) const;
	char& operator[] (const int index);
private:
    char* m_str; 
    static const char* desc;
    static int no_of_MyString_Obj;
};

#endif	/* MYSTRING_HPP */

