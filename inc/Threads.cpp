#include "Threads.hpp"

//int sum = 0;
//to avoid race conditions, replace above with
atomic <int> sum(0);


int square(int a) {
	cout << "value: " << a * a << endl;
	return a * a;
}

int cube_sum(int base) {
	sum = sum + base * base*base;
	return sum;
}

void doAsyncWork() {
	cout << "from inside doAsyncWork" << endl;
}

void threading() {
	cout << "Multithreading programming" << endl;

	std::thread thrd(&square, 5);
	thrd.join();

	//using threads to cube each elements of a vector
	vector <thread> int_v;


	for (int i = 1; i <= 10; i++) {
		int_v.push_back(std::thread(&cube_sum, i));
	}

	for (auto& v : int_v) {
		v.join();
	}
	cout << "cube sum using 10 threads: " << sum << endl;

	cout << "Task based: " << endl;
	auto value = std::async(doAsyncWork);
}