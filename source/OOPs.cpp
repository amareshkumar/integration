
#include "my_project_app.h"
#ifdef OOPS_MAIN

namespace oops{
	class shape {
	public:
		virtual void area(){
		}


	};

	template <class T>
	class Triangle {
	private:
		T base;
		T perp;
	public:


		virtual T area(){
			return 1 / 2 * base*perp;
		}
	};

	class Circle {
	public:
		int rad;
	};

	class Rectangle {
	private:
		int len, br;
	public:
		float calc_area(){
			return float(len * br);
		}
	};

	//=====================================================
	//Forward declaration of classes:
	class Manager;
	class Swipecard;
	class Worker;

	//Employee Class
	class Employee
	{
	private:
		char* company_name = "XYZ";
	public:
		Employee(){
			cout << "Employee object Constructed\n";
		}
		~Employee(){
			cout << "Empoyee object De-constructed\n";
		}
	};

	//Swipecard card


	class Swipecard
	{
	public:
		Swipecard(){
			cout << "Swipecard object Constructed\n";
		}

		~Swipecard(){
			cout << "Swipecard object De-constructed\n";
		}
		void swipe(Manager& mg){

			std::cout << "Manager card swiped\n\n";
		}
	};

	//Manager class
	class Manager : public Employee
	{
	private:
		int emp_id;
		float salary;
	public:
		//Workers List
		std::list<Worker> workers;

		Manager(){
			cout << "Manager object Constructed\n";
		}

		~Manager(){
			cout << "Manager object De-constructed\n";
		}
		float salary_detail(){
			if (true){
				salary = salary + 100.0f;
				cout << "Salary Increased by 100 bucks :)\n";
			}

		}
		void login(Swipecard& sp){
			cout << "Manager logged in\n";
		}

		void display_worker_list(){

			cout << "to do list\n\n";
		}

		void how_is_manager_good(bool good){

			cout << "Good";
		}

		//Aggregration
		//Manager has workers under him

	};

	class Worker {
	private:
		char* worker_name;
	public:
		Worker() {
			cout << "Worker object Constructed\n";
			worker_name = "default worker ";
		}
		Worker(char* worker_name) {
			cout << "Worker object Constructed\n";
			this->worker_name = worker_name;
		}
		char* get_worker_name(){
			return worker_name;
		}

		~Worker(){
			cout << "Worker object De-constructed\n";
		}
	};


	class Project {
		bool is_success;
	public:
		Project(Manager* mg){
			is_success = true;
		}
	};
	//=============================================================
}

class Test
{
protected:
	int x;
	const int y;
public:
	Test(): y(10){
	}
	Test(int i) :x(i), y(i) {}
	void fun() const
	{
		cout << "\nfun() const called " << endl;
		//x = 20;
	}
	void fun()
	{
		cout << "\nfun() called " << endl;
		x = 20;
		cout << "Value of x: " << x<<std::endl;
	}
	void get_data(){
		cout<<"y:"<<y;
	}
};

class Empty
{};

class Derived1 : public Empty
{};

class Derived2 : virtual public Empty
{};

class Derived3 : public Empty
{
	char c;
};

class Derived4 : virtual public Empty
{
	char c;
};

class Dummy
{
	static char* c;
};

class T1;
class T2;
class T3;
class T4;
class T5;


class T2{
public:
	virtual void display();
	virtual int calculate_median();
	virtual float area();
	virtual bool isSucceded();
	virtual bool isSucceded2();
	int calculate_median2(){
	}
	char* name(){
		return " test";
	}

};
class T1:public T2{
};
class T3 {
private:
	int ivalue;
	int ivalue2;
	int ivalue3;
	float fvalue;
	float fvalue2;
	float fvalue3;
	float fvalue4;
	int ivalue4;
	int ivalue5;
	float fvalue5;
	float fvalue6;
	double dvalue; //strange why it took 12 byte
	double dvalue2;
	double dvalue3;
	double dvalue4;
	long lvalue;	
	long lvalue2;	//why didn't increase the value
	long lvalue3;

	static float fvalue_s;
	static float fvalue2_s;
	static float fvalue3_s;
	static float fvalue4_s;
	static float fvalue5_s;
	static float fvalue6_s;

	
	static int ivalue_s;
	static int ivalue2_s;
	static int ivalue3_s;
	static int ivalue4_s;
	static int ivalue5_s;


};

class T4 {
	int ivalue;
	float fvalue;

};
class T5{
public:
	static void display();
};

using namespace oops;
/*
int main(){
	Manager* manager = new Manager(); //create a dynamic object of Manager type
	Swipecard* card = new Swipecard(); //create a dynamic object of Swipecard type

	cout << "\n\"Association\":\n";

	manager->login(*card);
	card->swipe(*manager);

	std::list<int> my_int_list(10);
	
	//create Workers objects
	cout << "\n\"Aggregation\":\n";
	Worker* worker = new Worker("Contractor");
	manager->display_worker_list();


	delete card;
	delete manager;
	delete worker;

	cout << "\"Composition\":\nTo Do!\n";;
	cout << "\n==================\n";
	Test t1(10);
	const Test t2(20);
	t1.fun();
	t1.get_data();
	t2.fun();
	cout << "\n==================\n";
		cout << "sizeof(Empty) " << sizeof(Empty) << endl;
		cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
		cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
		cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
		cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
		cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
		std::cout << "== == == == == == == == == == == == == == == == = \n";
		
		string line;
		ifstream myfile("./test.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';
			}
			myfile.close();
		}

		else cout << "Unable to open file";  
		myfile.close();

		streampos begin, end;
		ifstream myfile2("main.cpp", ios::binary);
		begin = myfile2.tellg();
		myfile2.seekg(0, ios::end);
		end = myfile2.tellg();
		myfile2.close();
		cout << "size is: " << (end - begin) << " bytes.\n";

		std::cout << "new:\n";

		ifstream in;
		in.open("main.cpp");
		std::cout << "== == == == == == == == == == == == == == == == = \n";
		
		
		cout << "size of \nT1: "<<sizeof(T1)<<"\nT2: "<<sizeof(T2)<<"\nT3: "<<sizeof(T3)<<"\nT4: "<<sizeof(T4)<<"\nT5: "<<sizeof(T5);
		return 0;


}
*/

#endif 