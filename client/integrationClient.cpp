#include "integrationClient.h"
#include "/home/amaresh/code/integration/inc/btree.hpp"

int main () {

    //commented for direct testing
	//utility::start ();

	int arr [] = {15, 10, 100, 5, 13, 90, 80, 50, 10, 5, 3};
    int len = sizeof(arr)/sizeof(*arr);

	using namespace btree;
	//create an instance of btree::tree;
	btree::tree* tree = new btree::tree();
	tree->create_btree (arr, len);

	//now display tree
	tree->display_btree_i (tree->get_root_btnode());

	return 0;
}

