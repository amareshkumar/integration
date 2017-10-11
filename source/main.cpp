#include <iostream>
#include "calc.h"
#include "MyLogger.hpp"

using namespace std; 

int main(void) {
     cout << "Welcome to integration project" << endl;
	 //double salary = avg_salary(3);

	 //cout << salary << endl;

	 MyLogger *logger = MyLogger::get_instance();
	 logger->log_msg ("This is new log");
	 logger->log_msg("average salary for persoon with experience 2 years is: ");
	 //logger->log_msg(avg_salary(2));

     return(0);
}