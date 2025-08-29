#pragma once

#ifndef MODERN_HPP
#define MODERN_HPP

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std; 

class Movable {
public:
#ifdef TEMP
	//c-tor default
	Movable() = default; 
	//copy ctor 
	Movable(const Movable& cp) = default;
	//assignment operator 
	Movable& operator=(const Movable& assign) = default;

	//move c-tor
	Movable(Movable &&mc) = default;

	Movable& operator=(Movable &&massign) = default;

	void details() { cout << "inside Movable::details()"; }
#endif 
	//c-tor default
	Movable(size_t m_size = 0) : m_size (0), m_data (nullptr) {
		log("constructor");
	}
	
	//copy ctor 
	Movable(const Movable& cp): m_size (cp.m_size), m_data ((m_size) ? (new int [m_size]):nullptr) {
		log("copy-constructor");
		for (size_t i = 0; i < m_size; ++i)
			m_data[i] = cp.m_data[i];
	}
	
	//assignment operator 
	//this also works
	Movable& operator=(const Movable& assign) {
		log("copy assignment operator");
		Movable temp(assign);

		std::swap(*this, temp);
		return *this;
	} 
	
	/* Following isnt supported in visual studio 
	friend void swap(Movable& first, Movable& second) // nothrow
	{
		// enable ADL (not necessary in our case, but good practice)
		using std::swap;

		// by swapping the members of two objects,
		// the two objects are effectively swapped
		swap(first.m_size, second.m_size);
		swap(first.m_data, second.m_data);
	}
	
	Movable& operator=(Movable assign) {
		log("copy assignment operator");
		//no self-assignment check rquired here
		std::swap(*this, assign);
		return *this;
	}*/

	//delete move-ctor and move assignment operator
	//Movable(Movable &&mc) = delete;
	//Movable& operator=(Movable&& mak) = delete;
	
	//move c-tor
	Movable(Movable &&mc): Movable() {
		log("move-constructor");
		std::swap(*this, mc);
	}

	Movable& operator=(Movable &&massign) {
		log("move assignment operator");
		std::swap(m_size, massign.m_size);
		std::swap(m_data, massign.m_data);
		
		return *this;
	}

	~Movable() {
		log("destructor");
		if (m_data) { delete [] m_data; m_data = 0; }
	}

	void details() { cout << "inside Movable::details()" << endl; }
private:
	void log(char *msg) {
		cout << "[" << this << "] " << msg << endl;
	}

	int *m_data; 
	size_t m_size;
};

#endif
