/*
 * node.h
 *
 *  Created on: Jan 7, 2016
 *      Author: amakumar
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>

using namespace std;

//node class for single linked list operations
//namespace linkedlist {
//	class node {
//		node(int value): info(value), next(nullptr){
//		}
//		int info;
//		node* next;
//	};
//}

//node class for doubly linked list
namespace dlinkedlist {
	class node {
		public:
			node(int data): info(data), prev (nullptr), next(nullptr){ cout << "node c-1-tor" << endl; }
			//node (): info (0), prev (nullptr), next(nullptr){ cout << "node c-tor" << endl; }
			int get_info () { return this->info; }
			node* get_next () {	return this->next; }
			node* get_prev () { return this->prev; }
			~node(){ cout << "node d-tor" << endl; }
		public:
			int info;
			node *next;
			node *prev;
	};
}

#endif /* NODE_H_ */
