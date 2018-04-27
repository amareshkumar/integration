#ifndef BTREE_H_
#define BTREE_H_

//btnode class

namespace btree {
class btnode {
public:
	btnode(int data): m_info(data), m_left(nullptr), m_right (nullptr) {}

	btnode* get_left_btnode ()  { return m_left; }
	btnode* get_right_btnode () { return m_right; }
	int get_data () { return m_info;}
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
	~tree();

	//create a tree: complete tree
	void create_btree (int arr[], int len);

	//in-order traversal
	void display_btree_i (btnode *root);
	void add_a_btnode (btnode* btnode, int data);

	inline btnode* get_root_btnode () { return m_root_btnode; }

private:
	btnode* m_root_btnode;
};

}
#endif
