#include "C11.hpp"

C11Class::C11Class(const C11Class &cp) {}
C11Class::C11Class(C11Class &&mp) {}

C11Class &C11Class::operator=(const C11Class &op)
{
	return *this;
}

C11Class &C11Class::operator=(C11Class &&rhs)
{
	return *this;
} //move assign op