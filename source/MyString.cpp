/* 
 * File:   MyString.cpp
 * Author: amakumar
 *
 * Created on July 27, 2015, 1:58 PM
 */

#include "MyString.hpp"


int MyString::no_of_MyString_Obj = 0;
extern MyLogger* mylog; 
const char* MyString::desc = "MyString";


MyString::MyString():m_str(NULL){
    mylog->log_msg("MyString C-tor\n");
    no_of_MyString_Obj++;
}

MyString::MyString(const char* st):m_str(NULL){
    m_str = const_cast <char*> (st); 
    mylog->log_msg("MyString 1-C-tor\n");
    no_of_MyString_Obj++;
}

MyString::~MyString(){
    //delete the memory allocated in copy c-tor
    //delete m_str; 
    mylog->log_msg("MyString D-tor\n");
    no_of_MyString_Obj--;
}

MyString::MyString(const MyString& str){
    m_str = new char [sizeof (str)];
    m_str = str.m_str; 
    mylog->log_msg("MyString copy c-tor called\n");
    no_of_MyString_Obj++;
}

MyString& MyString::operator = (const MyString & str){
    delete [] m_str; 
    
    m_str = str.m_str; 
    return *this; 
}

char* MyString::GetMyString(){
    return m_str; 
}

int MyString::Get_No_of_MyString_Obj() const{
    return no_of_MyString_Obj;
}

void MyString::SetMyString(const char* st) {
    m_str = const_cast<char*>(st); 
}

char* MyString::MyStringReverse (char *str2Reverse){
    int i, j = 0;
    int st_len = strlen(str2Reverse);  // replace with your own function
    
    char* mystr = new char [sizeof(str2Reverse)];
    
    //mystr = str2Reverse; 
    
    mylog->log_msg("Inside MyStringReverse func...");
    //mylog->log_msg("The value of mystr is: ");
    //mylog->log_msg (mystr);
    
    mylog->log_msg("Before the loop for reverting the string\n");
    for (i = 0, j = st_len - 1; i < st_len; i++, j--){
        mystr[i] = str2Reverse[j];
//        cout << "mystr at i = "<<i<<" "<<mystr[i];
//        cout << " ";
//        cout << "str2Reverse at j = "<<j<<" "<<str2Reverse[j];
    }
    mylog->log_msg("After the loop for reverting the string");
    mylog->log_msg(mystr);
    return mystr;
}

//char* MyString::operator+ (const char* str){
//    strcpy (this->m_str, str);
//    return m_str; 
//}

//MyString& operator+ (MyString& str) const {
//    MyString mystr; 
//    
//    mystr.m_str = this->m_str + str.m_str; 
//}

const char& MyString::operator[] (const int index) const {
	//return (static_cast <string>((*this).m_str))[index];
	return m_str[index];
}

char& MyString::operator[] (const int index) {
	//return (static_cast <string>((*this).m_str))[index];
	return m_str[index];
}

char* MyString::myAppend (char* strToAppend) {
    static int i; 
    int j = 0;
    char* temp = new char [sizeof(this->m_str) + sizeof(strToAppend)]; 
    
    mylog->log_msg(this->m_str);
    mylog->log_msg(" + ");
    mylog->log_msg(strToAppend);
    
    for (i = 0; i < strlen(this->m_str); i++){
        temp[i] = this->m_str[i];
    }
    
    for (j = 0; j < strlen(strToAppend); j++ ){
        temp [i+j] = strToAppend[j];
    }
    mylog->log_msg ("After appending: ");
    mylog->log_msg (temp);
    return temp; 
}

bool MyString::check_anagram_words (string first, string second){
	static bool flag = false;
	if (first.size() != second.size()) return false;

	for (int i = 0; i < first.size(); i++) {
		char temp = first[i];
		//cout << "temp:" << temp << endl;
		for (int j = 0 ; j < second.size(); j++ ) {
			//cout << "second[j]: " << second[j] << endl;
			if (temp != second[j]) {
				if (j != second.size()-1) { continue; } else { flag = false; return flag;}
				flag = false;
				continue;
			}
			else {
				flag = true;
				break;
			}
		}//end of inner loop
		if (i != first.size()-1) { continue; }   //else { flag_re = flag; }//return flag;}
	}//end of outer for loop

	//To check the other way round
	static bool flag_re = false;
	for (int i = 0; i < second.size(); i++) {
			char temp = second[i];
			//cout << "temp:" << temp << endl;
			for (int j = 0 ; j < first.size(); j++ ) {
				//cout << "second[j]: " << first[j] << endl;
				if (temp != first[j]) {
					if (j != first.size()-1) { continue; } else { flag_re = false; return flag_re;}
					flag_re = false;
					continue;
				}
				else {
					flag_re = true;
					break;
				}
			}//end of inner loop
			if (i != first.size()-1) { continue; }   //else { flag_re = flag; }//return flag;}
		}//end of outer for loop

	//if (flag && flag_re) { return true; } else { return false; }
	return (flag && flag_re) ? true:false;
}

bool MyString::check_palindrome_sent(string sent){
	int counter1 = 0;
	int counter2 = sent.size();
	bool flag = true;
	int i, j;
	//cout << "value of counter1: " << counter1 << "and counter2: " << counter2 << endl;
	for (i = counter1, j = counter2-1; i <= j; i++, j--) {
			//cout << "value of i = " << i << " value of j: " << j << endl;
			if (sent[i] == sent[j]) {
				//cout <<"Match" << endl;
				continue;
			}
			else {
				flag = false;
				//cout <<"Didn't match" << endl;
				return flag;
			}
	}
	return flag;
}
