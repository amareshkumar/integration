#pragma once
#ifndef C11_HPP
#define C11_HPP

#include "my_project_app.h"

class C11Class
{
public:
	C11Class() = default;
	~C11Class() = default;

	C11Class(const C11Class &cp); //copy ctor
	C11Class(C11Class &&mp);	  //move ctor

	C11Class &operator=(const C11Class &op); //copy assign op
	C11Class &operator=(C11Class &&rhs);	 //move assign op
};
#endif
