#ifndef BTREE_H_
#define BTREE_H_

namespace btree {

//btnode class
class btnode {
public:
	btnode(int data): m_info(data), m_left(nullptr), m_right (nullptr) {}
public:
	int m_info;
	btnode* m_left;
	btnode* m_right;
};

//tree class
class tree {
public:
	//construct a complete binary tree
	tree ();
	tree(int arr[], int len);
	~tree();

	//in-order traversal
	void display_btree_in();
	void display_btree_i(btnode* &root);
	void add_a_btnode (btnode* &btnode, int data);

private:
	static btnode* m_root_btnode;
	static btnode* m_root;
};

}
#endif
