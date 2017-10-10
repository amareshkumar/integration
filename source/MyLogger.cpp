#include "MyLogger.hpp"
#include <cstring>

MyLogger* MyLogger::pInstance_ = NULL;
//template <typename msg_type>
//msg_type MyLogger::m_log_str = NULL;  
char* MyLogger::m_log_str = NULL;  

//Create the only object of MyLogger and make it available to others files
MyLogger* mylog = MyLogger::get_instance();

void MyLogger::log_msg (const char* writeThis){
    fstream myfile; 
    myfile.open("C:/selfdev/logger.txt", ios_base::in | ios_base::app);
    myfile << writeThis << endl;
}

//To fix
//template <typename T>
//void MyLogger::log_msg (T writeThis) {
//    fstream myfile; 
//    myfile.open("D:/code2/amareshapp/logger.txt", ios_base::in | ios_base::app);
//    myfile << writeThis <<endl;
//}
//template void MyLogger::log_msg (const char*);
//template void MyLogger::log_msg (char*);
//template void MyLogger::log_msg (int);
//template void MyLogger::log_msg (std::string);
//template void MyLogger::log_msg (double);
//template void MyLogger::log_msg (float);

//No affect of following code so disabling it. 
//char* MyLogger::operator+ (const char* str) const {
//    mylog->log_msg("MyLogger::operator+ called with str arguments");
//    strcpy (this->m_log_str, str);
//    return m_log_str; 
//}
