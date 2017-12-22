#pragma once
#ifndef TREE_H
#define TREE_H

void root_to_leaf_paths(struct tnode* root);
void root_to_leaf_paths(struct tnode* root, int paths[], int pathlengh);
void printGivenLevel(struct tnode* root, int level);
void printLevelorder(struct tnode* root);
void print_post(struct tnode* root);
void print_pre(struct tnode* root);
void print_in(struct tnode* root);
int t_hight(struct tnode* root);
bool check_identical_trees(struct tnode* root1, struct tnode* root2);
struct tnode* insert_tnode(int item);

#endif //TREE_H
