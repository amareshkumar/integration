#include "fp.hpp"

void func1() {
	cout << "inside func1" << endl;
}

int simple_sum(int a, int b) {
	return a + b;
}

void another1() {
	cout << "another1" << endl;
}

void fn_pointer() {

	cout << "Direct call: " << endl;
	func1();

	cout << "Using fp: " << endl;
	void(*pf) () = &func1;
	(*pf)();

	void(*p_another) () = pf;
	pf = &another1;
	cout << "After assignment of fp to p_another" << endl;
	cout << "using p_another" << endl;
	(*p_another)();
	cout << "using pf " << endl;
	(*pf)();
	cout << endl;

	cout << "another using fp2" << endl;
	int(*pf2)(int, int) = &simple_sum;
	cout << "sum " << (*pf2)(3, 2) << endl;
}