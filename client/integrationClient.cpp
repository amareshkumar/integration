#include "integrationClient.h"
#ifdef __unix__
#include "/home/amaresh/code/integration/inc/btree.hpp"
#else()
#include "d:/code/integration/inc/btree.hpp"
#endif

int main () {

    //commented for direct testing
	//utility::start ();

	int arr [] = {15, 10, 100, 5, 13, 90, 80, 50, 10, 5, 3};
    int len = sizeof(arr)/sizeof(*arr);

	using namespace btree;
	//create an instance of btree::tree;
	btree::tree* tree = new btree::tree();
	btree::btnode* root = tree->get_root_btnode();

	//create tree
	tree->create_btree (root, arr, len);

	//btree::btnode* root_modified = tree->get_root_btnode();
	//now display tree
	tree->display_btree_i (root);

	delete tree;

	return 0;
}

