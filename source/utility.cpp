/*
 * utility.cpp
 *
 *  Created on: 16/01/2016
 *      Author: amare_000
 */

#include "utility.h"

void utility::start (){
	std::cout << "=============================" << endl;
	std::cout << "Welcome to Amaresh Project" << endl;
	std::cout << "What you want to do" << endl;
	std::cout <<"\n\
			1. social_network_app\n\
			2. programming questions\n\
			3. Contact me\n\
			4. Polymorphism\n\
			5. Mutitheading\n\
			6. gc\n\
			7. social\n\
			8. overloading\n\
			9. Oops\n\
			10.Boost\n\
			11.Cpp11\n\
			12.data structure\n\
			99.Exit" << endl;
	cout << "Please input your choice: " ;
	int choice;

	cin >> choice;

	switch (choice){
		case SocailNetwork: {
			cout << "Not developed yet\n";
			break;
		}
		case ProgrammingQuestions: {
			programming_questions prog_q;
			//Display the current programs listings (read file)
			cout << "Here are the listings of programs:" << endl;

			fstream myfile;
			myfile.open ("D:/pro/code/linux/Programs.txt", ios_base::in);
				//cout << "File could not be opened" << endl;

			string line;
			while (getline (myfile, line)){
				cout << line << endl;
			}
			myfile.clear();
			myfile.close();

			int input;
			std::cin >> input;
				switch (input){
					case 22:{
						string user_command;
						cout << "Enter new string to reverse word-wise:\n";
						getline(std::cin, user_command);
						cout << prog_q.Reverse(user_command) << endl;
						//prog_q.Reverse(user_command);
						break;
					}
					case 23: {
						cout << "Enter size of array: " << endl;
						int size, value;
						cin >> size;
						vector <int> array;
						cout << "Please enter the array elements:" << endl;
						for (int i = 0; i < size; i++) {
							cin >> value;
							array.push_back(value);
						}
						cout << "Maximum difference is: " << prog_q.max_diff_arr_index(array) << endl;
					}
					case 99: { break; }
					default: {
						cout <<"This option is not listed!" << endl;
					}
				}
			break;
		}
		case datastructures: {
			cout << "\n\
			 111. Linkedlist\n\
			 112. Binary Trees\n\
			 113. Queues\n\
			 114. Stack\n\
			 115. Doubly Linkedlist\n\
				  Please enter your choice: ";
					int choice3;
					cin >> choice3;
					switch (choice3) {
						case 115: {
//							cout << "Doubly linked list implementation" << endl;
//							cout << "----------------------------------" << endl;
//
//							DLinkedList dlist;
//							for (int i = 0 ; i < 7; i++) { dlist.add_to_last (rand()%100 + 1); }
//
//							dlist.display_list();
//							cout <<"After removing last item, list is: " << endl;
//							dlist.remove_last_item();
//							dlist.display_list();
//							cout <<"Add to front: " << endl;
//							dlist.add_to_front( 1 );
//							dlist.display_list();
							cout << "To do" << endl;
							break;
						}
					}
			break;
		}
		case ContactMe: {
			cout << "Not developed yet\n";
			break;
		}
		case Cpp11: {
				cout << "==================================================\n";

				cout << "Print elements of an array using Lambda..." << endl;
				vector <int> myIntVect;

				for (int i = 0 ; i < 10; i++) {
					myIntVect.push_back(i);
				}
				std::for_each ( begin(myIntVect), end(myIntVect), [&](int elem ) { cout << elem++ << " "; } );
		}
		case GetMeOutOfHere: {
			break;
		}
		default: {
			cout << "Please enter a valid input! " << endl;
		}
	} //end of switch
} //end of start
