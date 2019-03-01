/* 
 * File:   MyLogger.hpp
 * Author: amakumar
 *
 * Created on July 28, 2015, 3:01 PM
 * To do: make the mylogger class templatized to log for all data types. 
 */

#ifndef MYLOGGER_HPP
#define	MYLOGGER_HPP

#include "my_project_app.h"

//template <typename msg_type>
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

	void log_msg(const char* log_str);
public:
	static std::fstream my_log_file;
	static char* m_log_str;
};

#endif	/* MYLOGGER_HPP */

