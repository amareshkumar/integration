/* 
 * File:   MyLogger.hpp
 * Author: amakumar
 *
 * Created on July 28, 2015, 3:01 PM
 * Modified on March 1st, 2019
 * To do: make the mylogger class templatized to log for all data types. 
 */

#ifndef MYLOGGER_HPP
#define	MYLOGGER_HPP

#include "my_project_app.h"

class MyLogger {
private:
	MyLogger() {}
	MyLogger(const MyLogger&) {}
	MyLogger& operator = (const MyLogger&) {}
	~MyLogger() { my_log_file.close(); }
	static MyLogger* pInstance_;
public:
	
	static MyLogger& get_instance() {
		if (!pInstance_)
			pInstance_ = new MyLogger;
		return *pInstance_;
	}

	template <typename T>
	void log_msg(T writeThis){
		fstream myfile;
		myfile.open("D://logger.txt", ios_base::in | ios_base::app);
		myfile << writeThis << endl;
	}

public:
	static std::fstream my_log_file;
};

#endif	/* MYLOGGER_HPP */

