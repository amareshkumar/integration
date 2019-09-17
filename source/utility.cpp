/*
 *  utility.cpp
 *
 *  Author: Amaresh Kumar
 *  Created on: 16/01/2016
 *  Modified on: April 26th 2018
 */

#include "utility.h"
#include "KumarAlgoImpl.h"

 //static function implementation
void utility::start() {
	std::cout << "\n################=============================" << endl;
	std::cout << "Welcome to Amaresh's Project \"Integration\"" << endl;
	std::cout << "=============================################\n" << endl;
	std::cout << "What do you want to do? Please select an option: " << endl;
	std::cout << "\n\
			1.	social_network_app\n\
			2. 	programming questions\n\
			3. 	Contact me\n\
			4. 	Polymorphism\n\
			5. 	Mutitheading\n\
			6. 	gc\n\
			7. 	social\n\
			8. 	overloading\n\
			9. 	Oops\n\
			10.	Boost\n\
			11.	Cpp11\n\
			12.	data structure\n\
			13.	Algo\n\
			99.	Exit" << endl;

	cout << "Please input your choice: ";
	int choice;
	cin >> choice;

	switch (choice) {
	case Algo: {
		std::cout << "\n\
						Algo section: enter your choice: \n\
						101. Check if a string is a palindrome \n\
						102. find quadruples with sum \"target\" among an given array of size nums \n\
						103. <To be added> \n " << endl;

		int algo_choice = 0;
		KumarAlgoImpl kumaralgoimpl; //object for Algo component
		cin >> algo_choice;

		switch (algo_choice) {
		case 101: {
			string input_str;
			std::cout << "Enter string to check if it is palindrome: ";
			getline(cin, input_str);

			if (kumaralgoimpl.isPalindrome(input_str)) {
				cout << "the input string is palindrome" << endl;
			}
			else {
				cout << "the input string isn't palindrome" << endl;
			}

			break;
		}

		case 102: {
			vector <int> array{ 1, 0, -1, 0, -2, 2 };
			int target = 0;
			vector<vector<int>> result;

			result = kumaralgoimpl.fourSum(array, target);
			//see the result
			for (auto ele : result) { for (auto el : ele) { cout << el << " "; } cout << endl; }

			break;
		}

		default: {
			cout << "Sorry, this choice isn't there implemented" << endl;
		}
		}
		break;
	}

	case ProgrammingQuestions: {
		programming_questions prog_q;
		//Display the current programs listings (read file)
		cout << "Here are the listings of programs:" << endl;

		fstream myfile;
		myfile.open("D:/pro/code/linux/Programs.txt", ios_base::in);
		//cout << "File could not be opened" << endl;

		string line;
		while (getline(myfile, line)) {
			cout << line << endl;
		}
		myfile.clear();
		myfile.close();

		int input;
		std::cin >> input;
		switch (input) {
		case 22: {
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
			cout << "This option is not listed!" << endl;
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

		for (int i = 0; i < 10; i++) {
			myIntVect.push_back(i);
		}
		std::for_each(begin(myIntVect), end(myIntVect), [&](int elem) { cout << elem++ << " "; });

		break;
	}

	case GetMeOutOfHere: {
		break;
	}

	case SocailNetwork: {
		cout << "Not developed yet\n";
		break;
	}

	default: {
		cout << "Please enter a valid input! " << endl;
	}
	} //end of switch
} //end of utitlity::start()
