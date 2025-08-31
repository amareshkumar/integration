/*
 * Triangle.h
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"
#include <iostream>

using namespace std;

class Triangle: public Shape {
public:
	Triangle(int base, int height) : base(base), height (height) {
		//cout << "Triangle constructor called. " << endl;
	}


	inline double get_area() override { 
		return base * height; 
	}
	
	inline double get_perimeter()override {
		return 0.0f;
	}
	
	string tri_name() const {
		return tname;
	}

	virtual ~Triangle() {
		//cout << "Triangle destructor called. " << endl;
	}
private:
	int base{0};
	int height{0};
	const string tname = "Scalene. ";
};

#endif /* TRIANGLE_H_ */
