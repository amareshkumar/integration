#include "btree.hpp"
#include <iostream>
#include "my_project_app.h"

using namespace std;
namespace btree {

btnode* tree::m_root_btnode = nullptr;
btnode* tree::m_root = nullptr;

tree::tree () {}

//create a tree: complete tree
tree::tree(int arr[], int len) {
	if (len > 0) {
		m_root_btnode = m_root = new btnode(arr[0]);
		std::cout << "a root btnode is added with data: " << arr[0] << endl;
	}
	else {
		std::cout << "please pass valid len of array!" << std::endl;
		return;
	}

	for (int i = 1; i < len; i++) {
		add_a_btnode(m_root_btnode, arr[i]);
	}
	std::cout << "Tree creation successful!!" << std::endl;
}

tree::~tree() {
	//m_root_btnode = nullptr;
}

void tree::add_a_btnode (btnode* &root, int data) {
	///check if tree is empty
	btnode *current = root;
	if (!current) {
		m_root_btnode = new btnode(data);
		return;
	}

	if (current->m_left != nullptr) {
		//can we add it as right child of current btnode?
		if (current->m_right != nullptr) {
			//recurse, until you find leaf node to add keeping the tree complete
			add_a_btnode (current->m_left, data);
		} else {
			current->m_right = new btnode(data);
		}
	} else {
		current->m_left = new btnode(data);
	}
	//std::cout << "a btnode is added with data: " << data << endl; //todo: why this prints more times than actually it should
}

//inorder traversal
void tree::display_btree_i(btnode* &root) {
	btnode* current = root;
	if (root == nullptr) {
		return;
	}

	display_btree_i(current->m_left);
	std::cout << current->m_info << " ";
	display_btree_i (current->m_right);
}

//to get difference of left and right subtree
int tree::tree_hight_diff (btnode* left, btnode* right) {
	return (height (left) - height(right));
}

int tree::height (btnode* root) {

	if (!root) {
		return 0;
	}

	return (max(height(root->m_left), height (root->m_right)) + 1);
}

void tree::display_btree_in() {
	if (m_root == nullptr) {
		std::cout << "No elem in tree!" << std::endl;
		return;
	}
	display_btree_i(m_root);
}

int tree::height() {
	if (m_root == nullptr) {
		return 0;
	}
	return height(m_root);
}

} //namespace btree
