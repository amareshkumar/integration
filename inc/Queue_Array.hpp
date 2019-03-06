#pragma once
#ifndef Queue_Array_HPP
#define Queue_Array_HPP

#include "my_project_app.h"
#define SIZE 50

class Queue {
private: 
	int arr [SIZE];
	int rear;
	int front;
public: 
	Queue ():rear(0), front(0){}
	void enqueue (int item);
	int dequeue ();
	void print();
};

#endif //