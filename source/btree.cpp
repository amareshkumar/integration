#include "btree.hpp"
#include <iostream>

using namespace std;
namespace btree{

tree::tree (): m_root_btnode (nullptr) {}

tree::~tree() {
	m_root_btnode = nullptr;
}

//creates a complete tree
void tree::create_btree (int arr[], int len) {
	btnode* root = get_root_btnode ();

	for (int i = 0; i < len; i++) {
		add_a_btnode (root, arr[i]);
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

	if (current->get_left_btnode() != nullptr) {
		//can we add it as right child of current btnode?
		if (current->get_right_btnode() != nullptr) {
			//recurse
			add_a_btnode (current->get_left_btnode(), current->get_data());
		} else {
			btnode* newbtnode = new btnode(data);
			current->m_right = newbtnode;
		}
	} else {
		btnode* newbtnode = new btnode(data);
//		current->get_left_btnode() = newbtnode;
		current->m_left = newbtnode;
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

}