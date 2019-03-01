#pragma once
#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include "my_project_app.h"

template <class T1, class T2>
class templatized {
private:
	int m_counter;
	string m_classname;
public:
	//c-tor
	templatized() :counter(0), classname(static_cast <string> ("templatized")) {}

	int get_counter() {
		return m_counter;
	}

	string know_class_name() {
		return m_classname;
	}

	bool is_bigger_name(T1 one, T2 two) {
		return ((one.know_classname).length() > (two.know_classname).length());
	}

	bool is_bigger_object_size(T1 one, T2 two) {
		return (sizeof(one) > sizeof(two));
	}

	//variadic template

	~templatized (){
	}
};

#endif //TEMPLATES_HPP