#pragma once 
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

void print(struct node* head);
void print_pre(struct tnode* root);
void insert_at_end_2(struct node** head, int value);
void create_a_loop(struct node** p_2_head);
int delete_this_node(struct  node* head, int id_to_remove);
struct node* delete_first_node(struct node* head);
struct node* insert_at_end(struct node* head, int new_data);
struct node* rand_initialize_list();
struct node* reverse_list(struct node* head);
struct node* node_at_pos_n(struct  node* head, int pos);
struct node* insert_at_front(struct node* head, int new_data);
struct node* insert_at_pos(struct node* head, int value, int position);
void delete_nodes_after_n(struct node **head, int m, int n);


#endif //INKED_LIST_H 