/*
 * DLinkedList.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: amakumar
 */



#include "DLinkedList.h"
using namespace dlinkedlist;

node* DLinkedList::phead = nullptr;
//node* DLinkedList::ptail = nullptr;

DLinkedList::DLinkedList (){
	cout << "dlinkedlist c-tor" << endl;
}
DLinkedList::~DLinkedList() {
	cout << "dlinkedlist d-tor" << endl;
}

void DLinkedList::add_to_front (int value) {
	node* newnode = new node (value);

	newnode->next = phead;
	phead = newnode;
	newnode->prev = phead;
}

//Using only phead; Without using ptail
void DLinkedList::add_to_last (int value) {
	node* newnode = new node (value);
	if (phead == nullptr) {
		//phead = new node(value);
		phead = newnode;
		newnode->prev = phead;
		//delete newnode; //It will crash the program if enabled as nodes should be there.
		return;
	}
	node *current = phead;

	while (current->next != nullptr) {
		current = current->next;
	}
	//current->next = new node (value);
	current->next = newnode;
	newnode->prev = current;
	//delete newnode;
}

////using ptail
//void DLinkedList::add_to_last (int value) {
//	node* newnode = new node (value);
//	if (phead == nullptr) {
//		//phead = new node(value);
//		phead = ptail = newnode;
//		newnode->prev = phead;
//		newnode->next = ptail;
//		//delete newnode; //It will crash the program if enabled as nodes should be there.
//		return;
//	}
//
//	node *current = phead;
//	while (current->next != nullptr) {
//			current = current->next;
//	}
//	//last node now
//    current->next = newnode;
//    newnode->prev = current;
//	ptail = newnode->next ;
//}

void DLinkedList::display_list () {
	node *current = phead;

	while (current) {
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
}

void DLinkedList::remove_last_item (){
	node *current = phead;

	while (current->next->next) {
			current = current->next;
	}
	delete current->next->next;
	current->next = nullptr;
}
