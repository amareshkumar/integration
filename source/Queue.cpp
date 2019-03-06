#include "Queue_Array.hpp"

using namespace std; 

void Queue::enqueue (int item) {
	if (rear == SIZE) {
		cout << "Queue is full " << endl;
		return;
	}
	arr[rear++] = item;
}

int Queue::dequeue (){
	if (rear== 0) {
		cout << "Queue is empty, Underflow" << endl;
	}
	
	return arr[front++];	
}

void Queue::print () {
	if (rear == 0) {
		cout << "Queue is empty, No element to display" << endl;
		return;
	}
	
	for (int i=front; i < rear; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}