/*
 * DLinkedList.h
 *
 *  Created on: Jan 7, 2016
 *      Author: amakumar
 */

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>
#include "node.h"
using namespace dlinkedlist;

class DLinkedList {
public:
	DLinkedList ();
	~DLinkedList();
	void add_to_last (int value);
	void remove_last_item ();
	void display_list () ;
	void add_to_front (int value);
private:
	static dlinkedlist::node *phead;
	//static node *ptail;
};

#endif /* DLINKEDLIST_H_ */
