#include "btree.hpp"
#include <iostream>

using namespace std;

//creates a complete tree
void tree::create_btree (int arr[]) {
	int len = sizeof(arr)/sizeof (arr[0]);
	btnode* cbtnode = get_root_btnode ();

	for (int i = 0; i < len; i++) {
		add_a_btnode (cbtnode, arr[i]);
	}
	std::cout << "Tree creation successful!!" << std::endl;
}

void tree::add_a_btnode (btnode* root, int data) {
	///check if tree is empty
	if (!root) {
		btnode* newbtnode = new btnode(data);
		root = newbtnode;
		return;
	}

	btnode* current = root;
	//
	if (current->get_left_btnode() != nullptr) {
		//can we add it as right child of current btnode?
		if (current->get_right_btnode() != nullptr) {
			//recurse
			add_a_btnode (current->get_left_btnode(), current->get_data());
		} else {
			btnode* newbtnode = new btnode(data);
			//current->get_right_btnode() = newbtnode;
		}
	} else {
		btnode* newbtnode = new btnode(data);
		//current->get_left_btnode() = newbtnode;
	}
	std::cout << "a root btnode is added with data: " << data << endl;
}

//inorder traversal
void tree::display_btree_i (btnode* root) {
	btnode* current = root;
	if (current == nullptr){
		return;
		std::cout << "No elem in tree!" << std::endl;
	}

	display_btree_i (current->get_left_btnode());
	std::cout << current->get_data() << " ";
	display_btree_i (current->get_right_btnode());
}
