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
	std::cout <<"Display tree: " << std::endl;
	tree.display_btree_in(); //todo: debug why print isn't working properly
	std::cout << std::endl;
	std::cout <<"Height of the tree: " << tree.height();
	std::cout << std::endl;

//	primesum codelab
//	Todo: debug following functionality
	std::cout << "######prime_sum#####" << std::endl;
	int number = 0;
	std::cout <<"Enter number: " ;
	std::cin >> number;
	KumarAlgoImpl algo;

	std::vector <int> sum_v(2);
	sum_v = algo.prime_sum (number);

	for (auto e: sum_v) { cout << e <<" ";}
	std::cout << std::endl;
	return 0;
}

