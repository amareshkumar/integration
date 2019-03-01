#pragma once
#ifndef C11_HPP
#define C11_HPP

#include "my_project_app.h"

class C11Class{
public:
	C11Class () = default;
	~C11Class() = default;

	C11Class(const C11Class& cp) {} //ctor
	C11Class(const C11Class&& mp) {} //move ctor
	
	C11Class operator = (const C11Class& op) const {} //copy assign op
	C11Class operator = (const C11Class&& mv) const {} //move assign op

	int no_of_words (const char* sent);
};
#endif
