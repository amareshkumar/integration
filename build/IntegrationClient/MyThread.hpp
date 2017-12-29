/* 
 * File:   MyThread.hpp
 * Author: akumar
 *
 * Created on 27 September, 2015, 4:58 PM
 */

#ifndef MYTHREAD_HPP
#define	MYTHREAD_HPP

#include "my_project_app.h"

#define HAVE_STRUCT_TIMESPEC

#include <pthread.h>
#include <thread>
#include <chrono>
#include <iostream>
//to use function sleep
#include <stdlib.h>
#include <cstdlib>

//Mutex
void* showUpdatedBalance (void *null);
void thread_func_mutex ();

//condition variable
void* watch_balance (void* null);
void* update_balance_cv (void* null);
void thread_func_cond();

//another set of threads function
//added on Dec 29th 2017
void* print_number(void *arg);

#endif	/* MYTHREAD_HPP */

