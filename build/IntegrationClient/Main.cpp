#include <iostream>
#include "MyString.hpp"
#include "MyThread.hpp"

using namespace std; 

//write function so that each thread prints different area of input string of int
void* print_number(void *arg) {
	int *value = (int*)arg;

	for (int i = 0; i < 20; i++) {
		if (value[i] == 0) {
			cout << "Thread with id " << " is printing " << value[i] << endl;
		}
		else {
			continue;
		}
	}
	pthread_exit(NULL);
	return NULL;
}


int main(int argc, char* argv[]) {
	cout << "Testing integrated-static-lib..." << endl; 
	//MyString mystring("amaresh kumar");
	//cout << "MyString value: " << mystring.GetMyString() << endl;

	cout << "Threading practises..." << endl;
	//intialize memory for an array of integers
	int *array = new int(20);

	for (int i = 0; i < 20; i++) {
		array[i] = i;
	}

	//create three threads
	pthread_t th1;

	pthread_create(&th1, NULL, print_number, (void*)array);

	pthread_join(th1, NULL);

	delete[] array;
	system("pause");
	return 0;
}