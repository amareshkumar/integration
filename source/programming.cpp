#include "my_project_app.h"

using namespace std; 

static const int command_max_size = 100;

string programming_questions::Reverse(string str)
{
	size_t uiSize = str.size();

	for (int i = 0; i < uiSize; ++i)
	{
		while (isspace(str[i]) && i < uiSize) ++i;

		int j = i;
		while ((!isspace(str[j])) && j < uiSize) ++j;

		int k = i;
		i = j;
		--j;

		while (k < j)
		{
			swap(str[k], str[j]);
			++k;
			--j;
		}
	}
	return str;
}

int programming_questions::max_diff_arr_index (vector <int> array) {
	static signed int diff = 0;
	unsigned int len = array.size();
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len-i-1; j++) {
			signed int diff1 = array[j+1] - array[i];

			if (diff < diff1 && (diff1 > 0)) {
				diff = diff1;
			}
			else {
				continue;
			}
		}//end of inner for
	}
	return diff;
}

//void matrix_op::replaceWithZero(){
//	static int arr[4][4] = { { 1, 2, 3, 4 },
//	{ 5, 6, 7, 8 },
//	{ 9, 10, 0, 11 },
//	{ 12, 13, 14, 15 } };
//	display(arr);  //see the matrix
//	for (int i = 0; i < 4; i++){
//		static int value = 0;
//		static int value_row = 0;
//		for (int j = 0; j < 4; j++){
//			if (arr[i][j] == 0){
//				value_row = i;
//				arr[value_row][value++] = 0;
//			}
//
//			value = j - 1;
//		}
//		arr[i][value] = 0;
//	}
//	cout << endl;
//	display(arr);  //see the resulted matrix
//}

//void display_info(){
//	std::cout << "Size of virtual (Base Class): "<<sizeof(Instrument)<<endl;
//	std::cout << "Size of virtual Wind (derived Class): " << sizeof(Wind) << endl;
//}

std::string& programming_questions::reverse(std::string &st, int init, int final){
	int lenght = st.size();
	string temp = "";
	for (int i = init; i < final; i++){
		temp[i] = st[i];
		st[i] = st[lenght - final + 1];
		st[lenght - final + 1] = temp[i];
	}
	return st;
}


std::string& programming_questions::reverse_word_wise(std::string &str){
	static int position = 0;;
	for (int i = position; i < str.size(); i++){
		if ((str[i] == '\t') || (str[i] == ' ')) {
			reverse(str, position, i);
			position = i;
		}
	}
	return str;
}



template <class T>
class stl_op {

public:
	//T calculate_median(T arr[]);
	//T* my_sort(T arr[]);
	//void my_set();
	//void my_map();
};


template < typename T>
//pass name of the array and the lenght of it
T calculate_median(T arr[]){
	int arr_len = int(sizeof (arr) / sizeof arr[0]); //length of array "arr"
	my_sort(arr);
	if ((arr_len % 2) == 0){
		return (arr_len / 2);
	}
	else
		return ((arr_len / 2) + 1);
}

template <typename T>
void print_array(T arr[]){
	int arr_len = int(sizeof (arr) / sizeof arr[0]); //length of array "arr"
	for (int i = 0; i < arr_len; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template < typename T >
T* my_sort(T arr[]){
	int i;
	int j;
	int key;
	int arr_len = int(sizeof (arr) / sizeof arr[0]); //length of array "arr"
	//Insertion sort
	//loop through the lenght 

	for (i = 1; i < arr_len; i++)
	{
		key = arr[i];
		j = i - 1;

		//	Move elements of arr[0..i-1], that are greater than key, to one position ahead
		//	of their current position 

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return arr;
}


void my_set(){
	std::set <std::string> myset = { "amaresh", "akhilesh", "kirti", "rashmi" }; //set of 4 names

	myset.insert({ "kumar", "kumari" }); //insert 2 more elements

	//print them
	for (const auto& elem : myset){
		cout << elem << endl;
	}
}


void my_map(){
	std::map <int, string> my_map;

	my_map.insert({ 1, "amaresh" });
	my_map.insert({ 2, "akhilesh" });
	my_map.insert({ 3, "kirti" });
	my_map.insert({ 4, "rashmi" });

	for (auto record : my_map){
		std::cout << record.first << "\t" << record.second<< "\n"; 
	}
}


void my_hash_map(){

	unordered_map <string, int> m_hashmap;
	m_hashmap["amaresh"] = 28;
	std::cout << m_hashmap["amaresh"] << endl;

	m_hashmap["akhilesh"] = 24;
	//m_hashmap.insert("Kirti", 22);
	//m_hashmap.insert("Rashmi", 15);
}

void print(){

	for (int i = 1; i <= 100; i++){

		if ((i % 5 == 0) && (i % 3 == 0)){
			std::cout << "FizzBuzz ";
			continue;
		}
		else if (i % 3 == 0){
			std::cout << "Fizz ";
			continue;
		}

		else if (i % 5 == 0){
			std::cout << "Buzz ";
			continue;
		}

		std::cout << i << " ";
	} //END Of for loop
}

std::string translateColumnIndexToName(int index){
	int quotient = (index) / 26;
	if (quotient > 0) {
		return translateColumnIndexToName(quotient - 1) + (char)((index % 26) + 65);
	}
	else {
		std::stringstream ss;
		ss << (char)((index % 26) + 65);
		std::string str = ss.str();

		return str;
	}

}

//#endif //#if __cplusplus >= 201103L
