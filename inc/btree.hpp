#ifndef BTREE_H_
#define BTREE_H_

//btnode class
class btnode {
public:
	btnode(int data): m_info(data), m_left(nullptr), m_right (nullptr) {}

	btnode* get_left_btnode ()  { return this->m_left; }
	btnode* get_right_btnode () { return this->m_right; }
	int get_data () { return this->m_info;}
private:
	int m_info;
	btnode* m_left;
	btnode* m_right;
};

//tree class
class tree {
public:
	//construct a complete binary tree
	tree (): m_root_btnode (nullptr) {}

	//create a tree: complete tree
	void create_btree (int arr[]);
	//in-order traversal
	void display_btree_i (btnode *root);
	void add_a_btnode (btnode* btnode, int data);
	//inline
	inline btnode* get_root_btnode () { return m_root_btnode; }
	~tree() { m_root_btnode = nullptr;}
private:
	btnode* m_root_btnode;
};

#endif
