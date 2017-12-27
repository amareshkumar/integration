#include "my_project_app.h"

//linkedin list node
struct node {
	int data;
	struct node* next;
};

void print(struct node* head) { //take first node as an argument (to traverse the list)
	struct node* current = head;  //take a temporery current pointer ( which initially points to head )
	while (current != NULL) {//while not last node
		std::cout << current->data << " ";
		current = current->next; //move to next node
	}
	//now last node
	return;
}

//return 1 if error; return 0 if successful. 
int delete_this_node(struct  node** head, int id_to_remove){
	struct node* temp = *head;

	if (temp == NULL) {
		cout << "nothing to delete\n";
		return 1;
	}

	while (temp->next != NULL){

		if (temp->data == id_to_remove){

			temp->data = temp->next->data;
			struct node* temp3 = temp->next;
			temp->next = temp->next->next;

			free(temp3);
			return 0;
		}

		temp = temp->next;
	}
	return 1;
}

//reverse a linked list; Iterative
//with help of three pointer
void reverse_list(struct node** head){

	struct node* prev = NULL;
	struct node* current = *head;
	struct node* next;

	while (current != NULL){
		next = current->next;

		current->next = prev; //why not next
		prev = current;
		current = next;
	}
	*head = prev;  //why not current??
}


struct node* rand_initialize_list() {
	//declare the head pointer as global
	struct node* head;
	struct node* second;
	struct node* third;
	struct  node* fourth;

	head = (node *)malloc(sizeof (node)); //initialize memory for head (first node) 
	second = (node *)malloc(sizeof (node)); //initialize memory for second node 
	third = (node *)malloc(sizeof (node)); //initialize memory for third node
	fourth = (node *)malloc(sizeof (node)); //initialize memory for fourth node

	head->data = 10;
	second->data = 20;
	third->data = 30;
	fourth->data = 40;

	//make head points to seond
	head->next = second;  //head points to second node
	second->next = third; //second node points to third
	third->next = fourth; //third points to fourth (last node)
	fourth->next = NULL; //fourthpoints to NULL (last node)

	//print(head);
	return head;
}


//function to return nth node in LL
//take head pointer as one input (pos as second)

struct node* node_at_pos_n(struct  node* head, int pos){
	struct node* current = head;
	int curr_pos = 1;
	while (curr_pos != pos){
		curr_pos++;
		current = current->next;
	}

	return current;
}

//delete first element of a linked list
struct node* delete_first_node(struct node* head) {
	//make head points to third element
	struct node* current;

	current = head;

	if (current == NULL){
		std::cout << "emplty list. cant delete\n";
		exit(1);
	}

	head = current->next;
	free(current);
	print(head);
	return head;
}

//insert at the front of existing list
struct node* insert_at_front(struct node* head, int new_data){
	struct node* new_node = (node*)malloc(sizeof (node)); //one new node is created here
	new_node->data = new_data;

	//make sure that it is not being added in emplty list
	if (head == NULL){
		cout << "empty list\n";
		cout << "adding new eleemnt in it";
		new_node->next = NULL;
		return new_node;
	}

	new_node->next = head;  //make new_node points to head (of existing list)

	print(new_node);
	return new_node;
}

//Insert a node at a given position (number)
//This will take a pointer to the head node and the value to be put in the new node
//Will return pointer to the head

struct node* insert_at_pos(struct node* head, int value, int position){
	//create memory for new node
	struct node* new_node = (node*)malloc(sizeof (node));
	new_node->data = value;  //insert data

	//traverse the list starting from head
	struct node* temp = head;  //make a temp pointer points where head points to
	int current_pos = 1;

	while (current_pos != position){
		current_pos++;
		temp = temp->next;
	}
	//make the new node points to the next of temp
	new_node->next = temp->next;
	//make the temp node points to new node
	temp->next = new_node;

	print(head);
	return head;
}


//insert a node at end
struct node* insert_at_end(struct node* head, int new_data){
	//step 1: create a node (allocate memory)
	struct node* new_node = (node*)malloc(sizeof (node)); //one new node is created here

	//step 2; insert the data into it
	new_node->data = new_data;

	//step 3 start from head

	struct node* temp = head;

	new_node->next = NULL;  //make new_node as last node

	//if it is empty list, make head points to new_node 

	if (temp->next == NULL){
		cout << "empty list\n";
		cout << "adding new eleemnt in it";
		temp = new_node;

		return temp;
	}

	//step 4;
	//traverse the list untill you find last node

	while (temp->next != NULL){
		temp = temp->next;			//make temp points to next node until it finds last one
	}

	temp->next = new_node;

	//head = temp;
	//free(temp);
	//print(head);

	return head;
}



void insert_at_end_2(struct node** head, int value){  //pointer to head pointer (pointer to pointer to head node)
	//create memory for new node
	struct node* new_node = (struct node*) malloc(sizeof (struct node));

	struct node* temp = *head;

	new_node->data = value;

	//make new_node as last node
	new_node->next = NULL;

	if (temp == NULL){
		std::cout << "empty list\n";
		temp = new_node;
		*head = temp;
		return;
	}

	//Else, traverse thourgh the list untill get last element
	while (temp->next != NULL){
		temp = temp->next;
	}
	//got the lst node
	temp->next = new_node;
	return;
}


//CREATE a loop in the list intentionally 
//loop: {third->fourth-fifth-sixth}
void create_a_loop(struct node** p_2_head) {
	struct node* temp = *p_2_head;


	//make 9 point to 5
	(*p_2_head)->next->next->next->next->next = (*p_2_head)->next->next;

	cout << "loop 5-7-8-9-5 successfully created\n";
}

void delete_nodes_after_n(struct node **head, int m, int n){
	struct node* current = *head;
	int i = 0;

	while (current!=NULL &&  i > n)
	{
			current = current->next;
	}
	//found the node to delete next m nodes
	struct node* here = current->next;

	for (int j = 0; j < m; i++){
		struct node* temp = here;
		here = here->next;
		free(temp);
	}

	current->next = here;
}


#if MAIN_LINKED_LIST

void main(int argc, char **argv){

	//create a list and populate it with
	//1,3,5, 7, 8, 9, 11,12

	//create a empty list, treat new_linked_list_head as head pointer 
	struct node* new_linked_list_head = NULL;


	insert_at_end_2(&new_linked_list_head, 1);
	insert_at_end_2(&new_linked_list_head, 3);
	insert_at_end_2(&new_linked_list_head, 5);
	insert_at_end_2(&new_linked_list_head, 7);
	insert_at_end_2(&new_linked_list_head, 8);
	insert_at_end_2(&new_linked_list_head, 9);
	insert_at_end_2(&new_linked_list_head, 11);
	insert_at_end_2(&new_linked_list_head, 12);

	//print the list => 1, 3, 5, 7, 8, 9, 11,12

	//create_a_loop(&new_linked_list_head);

	print(new_linked_list_head);

	if (!delete_this_node(&new_linked_list_head, 7)){
		cout << "\nDelettion Successful; \n";
	}
	else
	{
		cout << "\nelement not found\n";
	}

	std::cout << std::endl << "new list is:\n";
	print(new_linked_list_head);

	cout << "\nAfter reversing; List is: \n";

	reverse_list(&new_linked_list_head);

	print(new_linked_list_head);

	insert_at_end_2(&new_linked_list_head, 20);
	insert_at_end_2(&new_linked_list_head, 100);

	std::cout << std::endl;
	print(new_linked_list_head);
	
	//cout << "deleting m nodes after n nodes\n";
	//delete_nodes_after_n(&new_linked_list_head, 3, 4);
	//cout << "result:\n";
	//print(new_linked_list_head);
	//int x = 5;
	//int y = 3;
	//
	//cout << "\nx = " << x << "\ty = " << y << "\n";
	//
	//change_the_values(&x, &y);
	//
	//cout << "\nx = " << x << "\ty = " << y<<"\n";


	//call function to detect loop

	//Quiz 1:
	//access private member without using object

	//Test t;
	//int *p1;
	//p1 = (int *)&t;
	//*p1 = 10;

	//std::cout<< "t.data:"<<t.get_data();
	//Quiz 2: 
	// make line 466 illigal as it allocate memory non-dynamically

	//std::cout << std::endl;
	//
	//Test2* t2 = new Test2;

	//destructTest2(t2);


}


#endif //MAIN_LINKED_LIST
