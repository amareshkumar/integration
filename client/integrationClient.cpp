#include "integrationClient.h"

//existing cycle
class two;
class one {
public:
	shared_ptr <two> two_sp; 
};

class two {
public:
	shared_ptr <one> one_sp; 
};

class two_w;
//weak pointer: breaking know cycle
class one_w {
public:
	shared_ptr <two_w> two_sp; 
};

class two_w {
public:
	weak_ptr <one_w> one_wp; 
};

class B {
	int idata; 
public:
	virtual void display (int i) {
		cout <<"print int: " << idata << endl;
	}
};

class D : public B {
	protected:
float fdata; 
public:
	virtual void display (float f) {
		cout  << "print D: float: " << fdata << endl; 
	}
};

class DD : public D {
double ddata; 
public:
	void display (float f) {
		cout  << "print D: float: " << D::fdata << endl; 
	}
	void display (double d) {
		cout  << "print DD: double: " << ddata << endl; 
	}
};

int main () {

//#ifdef POLY
B* obj = new D(); 
obj->display (2.0);
obj->display (1);

D* d_obj = new D();
d_obj->display(2.0);
d_obj->display (1);

B* dd_obj = new DD();
dd_obj->display(5);
dd_obj->display(4.5f);
dd_obj->display(12345l);

delete obj; delete d_obj; delete dd_obj;

//#endif // POLY

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
	/*cout << "Decorator design pattern" << endl;

	IGirl* girl = new GirlWithExpensiveDress(new GirlWithHighHills (new GirlDrivingHarleyBike(new GirlWithNecklace(new GirlMakeUp(new Girl())))));
	
	girl->girl_type();

	delete girl;
	*/
	//client code snipped for Bridge design pattern
	MoveLogic *walklogic = new Walk();
	MoveLogic *swimLogic = new Swim();


	Animal *animal1 = new Person (walklogic);
	animal1->howDoIMove(); 
	
	Animal *animal2 = new Fish (swimLogic);
	animal2->howDoIMove();

	//doing same above things with smart pointers
	cout << "using smart auto keyword | dumb pointers: ";
	auto walklogic2 = new Walk();

	auto animal3 = new Person(walklogic2);
	animal3->howDoIMove();

#ifdef WHY_UNIQUE_POINTER

	// cout << "using shared ptr: ";
	// shared_ptr <MoveLogic> walklogic3 = make_shared <MoveLogic> ();
	// shared_ptr<Animal> animal4 = make_shared <Person> (walklogic3);
	// animal4->howDoIMove();

	// unique_ptr <MoveLogic> movelogic_sp = make_unique <MoveLogic> ();
	// unique_ptr <Animal> animal_sp = make_unique <Fish> (movelogic_sp);
	// animal_sp->howDoIMove();

	cout << "cycling pointers | shared ptr | memory leak" << endl;
	shared_ptr <one> x (make_shared <one>()); //+1
	cout << "x-ref_count: " << x.use_count() << endl;
	x->two_sp = make_shared <two>(); //+1
	x->two_sp->one_sp = x; //+1
	cout << "x-ref_count: " << x.use_count() << endl;


	// Ref count of 'x' is 2.
	// Ref count of 'x->b' is 1.
	// When 'x' leaves the scope, there will be a memory leak:
	// 2 is decremented to 1, and so both ref counts will be 1.
	// (Memory is deallocated only when ref count drops to 0)


	cout << "after using weak_ptr: " <<endl;
	//breaking the cycle with wp
	shared_ptr<one_w> x2(make_shared <one_w>()); // +1
	cout << "x-ref_count: " << x2.use_count() << endl;
	x2->two_sp = make_unique <two_w>();           // +1
	cout << "x-ref_count: " << x2.use_count() << endl;
	x2->two_sp->one_wp = x2;            // No +1 here
	//cout << "x-ref_count: " << x2.use_count << endl;

	// Ref count of 'x' is 1.
	// Ref count of 'x->b' is 1.
	// When 'x' leaves the scope, its ref count will drop to 0.
	// While destroying it, ref count of 'x->b' will drop to 0.
	// So both A and B will be deallocated.
#endif //WHY_UNIQUE_POINTER


}




