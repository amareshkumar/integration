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

	//create an instance of btree::tree;
	btree::tree tree (arr, len);

	//Display tree
	std::cout << std::endl;
	tree.display_btree_in();

	return 0;
}

