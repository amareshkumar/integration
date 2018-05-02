#include "integrationClient.h"
#include "/home/amaresh/code/integration/inc/dp.hpp"

#ifdef __unix__
#include "/home/amaresh/code/integration/inc/btree.hpp"
#include "/home/amaresh/code/integration/inc/dp.hpp"
#else()
#include "d:/code/integration/inc/btree.hpp"
#endif

int main () {

    //commented for direct testing
	//utility::start ();

//	int arr [] = {15, 10, 100, 5, 13, 90, 80, 50, 10, 5, 3};
//    int len = sizeof(arr)/sizeof(*arr);
//
//	//create an instance of btree::tree;
//	btree::tree tree (arr, len);
//
//	//Display tree
//	std::cout << std::endl;
//	std::cout <<"Display tree: " << std::endl;
//	tree.display_btree_in(); //todo: debug why print isn't working properly
//	std::cout << std::endl;
//	std::cout <<"Height of the tree: " << tree.height();
//	std::cout << std::endl;
//
////	primesum codelab
////	Todo: debug following functionality
//	std::cout << "######prime_sum#####" << std::endl;
//	int number = 0;
//	std::cout <<"Enter number: " ;
//	std::cin >> number;
//	KumarAlgoImpl algo;
//
//	for (auto e: algo.prime_sum (number)) { cout << e <<" ";}
//
//	std::cout <<"My String: " ;
//	MyString mystring;
//	std::cout << "lenght of last word: " << mystring.lengthOfLastWord("a weirg question about white space");
//	std::cout << std::endl;

	int choice = 0;
	std::cout <<"####DP####\n\nenter number: " ;
	Dp dp;
	cin >> choice;
	std::cout << "fact using dp: " << dp.fact(choice) << std::endl;
	std::cout << std::endl;

	std::cout << "fibonacci for number " << choice << " entered [using DP]: " << dp.fibonacci(choice) << std::endl;
	return 0;
}

