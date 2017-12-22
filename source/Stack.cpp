#include "my_project_app.h"
/***********************************
Linked list implentation of Stack
***********************************/

#ifdef STACK_MAIN

namespace my_stack{

	bool is_empty(struct stack_node*);
	bool is_ful();
	void push(struct stack_node**, int item);
	int pop(struct stack_node**);


#define Max_Stack_Size = 10;
	//structure of stack node

	struct stack_node {
		int data;
		struct stack_node* next;
	};

	//class of stack

	void push(struct stack_node** first, int item){

		stack_node* stackNode = (stack_node*)malloc(sizeof(stackNode));
		stackNode->data = item;

		if (*first == NULL){
			cout << "empty stack\nadding items...\n\n";
		}

		stackNode->next = *first;
		*first = stackNode;

		cout << "Item added:\t\"" << item << "\"" << endl;

	}

	void display_stack(struct stack_node* first){
		if (first == NULL) {
			cout << "No items\n";
			return;
		}

		while (first != NULL){
			std::cout << first->data << " ";
			first = first->next;
		}
	}

	int pop(stack_node** first){
		stack_node* temp = *first;

		if (temp == NULL){
			cout << "stack underflow\n";
			return 0;
		}
		if (temp->next == NULL){
			cout << "\npopped item:\t" << temp->data << endl;
			cout << "this was the last item in the stack";
		}

		(*first) = temp->next;
		cout << "\npopped item:\t" << temp->data << endl;
		return temp->data;

	}



	int peek(struct stack_node* root)
	{
		if (is_empty(root))
			return INT_MIN;
		return root->data;

		printf("Top element is %d\n", peek(root));
	}
	bool is_empty(stack_node* first){
		return false;
	}

	bool is_full(){
		return false;
	}
}

using namespace my_stack;

int main(){
	struct stack_node* first = NULL;

	push(&first, 11);
	push(&first, 21);
	push(&first, 31);
	push(&first, 41); 
	push(&first, 51);

	display_stack(first);
	std::cout << "Popping:\n";
	pop(&first);
	display_stack(first);
	pop(&first);
	display_stack(first);
	pop(&first);
	display_stack(first);
	pop(&first);
	display_stack(first);
	pop(&first);
	display_stack(first);

	//underflow check
	pop(&first);
}

#endif //STACK_MAIN