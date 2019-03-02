#pragma once
#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include "my_project_app.h"

template <class T1, class T2>
class Templatized {
private:
	int m_counter;
	string m_classname;
public:
	//c-tor
	Templatized() :m_counter(0), m_classname(static_cast <string> ("Templatized")) {}

	int get_counter() {
		return m_counter;
	}

	string know_class_name() {
		return m_classname;
	}

	template <typename T1, typename T2>
	bool is_bigger_object_size(const T1& one, const T2& two) {
		return (sizeof(one) > sizeof(two));
	}

	//variadic template

	~Templatized (){
	}
};

class Int_class {
private:
	int var1; 
public:
	int square_int() {
		return var1 * var1; 
	}

	string know_class_name() {
		return static_cast <string> ("Int_class");
	}
};

class Float_class {
private:
	float m_var_f; 
public:
	float double_float (){
		return 2.0f * m_var_f;
	}
	
	string know_class_name() {
		return static_cast <string> ("Float_class");
	}
};

template <class T> 
class ToBeDrived {
public:
	void display() {
		cout << "class: toBeDrived" << endl;
	}
};

template <class T>
class Derived : public ToBeDrived <T> {
public:
	T cube_int(T var) {
		return static_cast <T> (var * var * var);
	}
};

#endif //TEMPLATES_HPP