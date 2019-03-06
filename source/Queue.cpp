#include "Queue_Array.hpp"

using namespace std; 

void Queue::enqueue (int item) {
	
	if (rear == SIZE-1) {
		cout << "Queue is full " << endl;
		return;
	}
	//rear = rear+1;
	arr[++rear] = item;
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
	
	for (int i=0; i <= rear; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}