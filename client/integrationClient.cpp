#include "integrationClient.h"

#ifdef __unix__
#include "/home/amaresh/code/integration/inc/btree.hpp"
#include "/home/amaresh/code/integration/inc/dp.hpp"
#else()
#include "d:/code/integration/inc/btree.hpp"
#include "d:/code/integration/inc/dp.hpp"
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
	
	//Threading practises
	//threading();

	//function pointers
	//fn_pointer();
	
	//Singleton patterns and class practises
	/*MyLogger& logger = MyLogger::get_instance();
	logger.log_msg("Hello Singleton");
	logger.log_msg(2);*/
	//Templates and Metaprogramming
	/*
	Derived <int> derived;
	derived.display();
	cout << "cube from Derived::cube_int(): " << derived.cube_int(5) << endl;

	Templatized <Int_class, Float_class> templatized;
	Int_class* intclass = new Int_class(); 
	Float_class* floatclass = new Float_class(); 

	cout << "is int class object size is bigger: " 
		<< templatized.is_bigger_object_size(*intclass, *floatclass) << endl;
	*/
	//Queue impl using array
	/*Queue queue;

	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(7);
	queue.enqueue(9);
	queue.print();

	cout << "after 1st deueue: " << queue.dequeue() << " Queue is: ";
	queue.print();
	cout << "after 2nd element: " << queue.dequeue() << " Queue is: ";
	queue.print();
	cout << "after 3rdd element: " << queue.dequeue() << " Queue is: ";
	queue.print();

	cout << "again 2 more enqueues: " << endl;
	queue.enqueue(13);
	queue.enqueue(15);
	cout << "Queue now is: ";
	queue.print();*/
	
	//cout << "CI Practises" << endl;

	//Driver for observer design pattern
	/*Subject subject; 
	OldConcreteObserver old_observer(&subject, 100);
	OldConcreteObserver old_observer2(&subject, 200);

	YoungConcreteObserver young_observer1(&subject, 50);
	YoungConcreteObserver young_observer2(&subject, 150);

	subject.setScored(true);
	*/

	//Driver for Abstract design pattern
	//Mobile companies facotry patters
	/*Abs_MobileFactory *abs_mobile_factory;

	//generic mobile product abstract
	Smartphone *smartphone;

	//acutal concerete products
	//Blackberry is needed from customer
	abs_mobile_factory = new BlackBerryFactory;

	//BlackBerryFactory creates a product called Blackberry
	smartphone = abs_mobile_factory->createSmartphone();
	
	//use the product : blackberry
	smartphone->which_smart_phone();

	//Now client needs an Iphone
	abs_mobile_factory = new IphoneFactory;

	//IphoneFactory creates a product "Iphone" for use
	smartphone = abs_mobile_factory->createSmartphone();

	//use iphone
	smartphone->which_smart_phone();


	abs_mobile_factory = new AndroidFactory;
	smartphone = abs_mobile_factory->createSmartphone();
	smartphone->which_smart_phone();*/

	
	//Driver code for Decorator design pattern
	cout << "Decorator design pattern" << endl;

	IGirl* girl = new GirlWithExpensiveDress(new GirlWithHighHills (new GirlDrivingHarleyBike(new GirlWithNecklace(new GirlMakeUp(new Girl())))));
	
	girl->girl_type();

	delete girl;
}




