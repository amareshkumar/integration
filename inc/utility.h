/*
 * utility.h
 *
 *  Created on: 16/01/2016
 *      Author: amare_000
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "my_project_app.h"

enum EUserInput {
	SocailNetwork 			= 1,
	ProgrammingQuestions 	= 2,
	ContactMe 				= 3,
	Polymorphic 			= 4,
	Multithreading 			= 5,
	GC 						= 6,
	Social 					= 7,
	Oops					= 9,
	Boost					= 10,
	Cpp11					= 11,
	datastructures			= 12,
	Algo					= 13,
	String					= 14,
	GetMeOutOfHere 			= 99
};

class utility {
public:
	static void start ();
};

#endif /* UTILITY_H_ */
