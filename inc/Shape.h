/*
 * Shape.h
 *
 *  Created on: Dec 7, 2015
 *  *  Modified on: April 24th, 2018
 *      Author: amakumar
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#ifdef _WIN64
#include <windows.h>
#endif

#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	virtual double get_area () = 0;
	virtual double get_perimeter() = 0;

	virtual ~Shape() {
	}
};

#endif /* SHAPE_H_ */
