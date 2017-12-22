#include "my_project_app.h"


//structure of a binary tree
struct tnode {
	int data;
	struct tnode* left;
	struct tnode* right;

};


//function create a new tnode
//return tnode*

struct tnode* insert_tnode(int item){
	//intialize memory for new tree tnode
	struct tnode* new_tnode = (struct tnode*) malloc(sizeof (struct tnode));
	new_tnode->data = item;  //assign item to it as data

	//struct tnode* temp;
	//temp = root;
	//
	////tree is empty
	//if (temp == NULL){
	//	temp = new_tnode;
	//}
	//if (item < temp->data )//go left sub-tree
	//	insert_tnode(root->left, item);
	//else {
	//	insert_tnode(root->right, item);
	//}

	new_tnode->left = NULL;
	new_tnode->right = NULL;

	return (new_tnode);
}

void print_in(struct tnode* root){
	struct tnode* temp = root;
	if (temp == NULL){

		return;
	}

	print_in(temp->left);
	std::cout << temp->data << "\t";
	print_in(temp->right);
}

int tree_size(struct tnode* root){

	if (root == NULL){
		return 0;
	}
	return (tree_size(root->left) + 1 + tree_size(root->right));
}

void print_pre(struct tnode* root){
	struct tnode* temp = root;
	if (temp == NULL){

		return;
	}
	std::cout << temp->data << "\t";
	print_pre(temp->left);
	print_pre(temp->right);
}

void print_post(struct tnode* root){
	struct tnode* temp = root;
	if (temp == NULL){

		return;
	}

	print_post(temp->left);
	print_post(temp->right);
	std::cout << temp->data << "\t";
}


bool check_identical_trees(struct tnode* root1, struct tnode* root2){
	if (root1 == NULL && root2 == NULL){
		return true;
	}

	else  {
		return ((root1->data == root2->data) &&
			(check_identical_trees(root1->left, root2->left)) &&
			(check_identical_trees(root1->right, root2->right)));
	}

	return false;
}

void print_path_leaf(int paths[], int pathlenght){

	for (int i = 0; i < pathlenght; i++){
		std::cout << "->" << paths[i];
	}
}

void root_to_leaf_paths(struct tnode* root, int paths[], int pathlengh){

	if (root == NULL){
		return;
	}

	paths[pathlengh] = root->data;
	pathlengh++;

	if (root->left == NULL && root->right == NULL){
		print_path_leaf(paths, pathlengh);
		std::cout << "\n";
	}
	//traverse left subtree
	else {
		root_to_leaf_paths(root->left, paths, pathlengh);
		root_to_leaf_paths(root->right, paths, pathlengh);
	}

}

void root_to_leaf_paths(struct tnode* root){
	int paths[1000];
	root_to_leaf_paths(root, paths, 0);
}


//print height of a tree (given root node pointer)
int t_hight(struct tnode* root){
	if (root == NULL) {
		return 0;
	}
	int l_t_height = t_hight(root->left);
	int r_t_height = t_hight(root->right);

	if (l_t_height > r_t_height)
		return l_t_height + 1;
	else
		return r_t_height + 1;
}

///*Function to print level order traversal of tree*/
void printLevelorder(struct tnode* root){
	int height = t_hight(root);
	for (int i = 1; i <= height; i++)
	{
		printGivenLevel(root, i);
		std::cout << " ";
	}
}

///*Function to print all nodes at a given level*/
void printGivenLevel(struct tnode* root, int level) {

	if (root == NULL)
		return;

	if (level == 1)
		cout << root->data << " ";

	else if (level > 1){
		printGivenLevel(root->left, (level - 1));
		printGivenLevel(root->right, (level - 1));
	}

}


#ifdef TREE_MAIN
int main(){
	//create a empty tree
	//struct tnode* root = insert_tnode(40);

	//root->left = insert_tnode(20);
	//root->left->left = insert_tnode(10);
	//root->right = insert_tnode(60);
	//root->left->right = insert_tnode(30);
	//root->right->left = insert_tnode(50);
	//root->right->right = insert_tnode(70);

	//std::cout << "\nin-order\n";
	//print_in(root);
	//
	//std::cout << "\npre-order\n";
	//print_pre(root);
	//
	//std::cout << "\npost-order\n";
	//print_post(root);
	//
	//cout << "\n\ntree size: " << tree_size(root);


	struct tnode* root1 = insert_tnode(50);
	root1->left = insert_tnode(15);
	root1->left->left = insert_tnode(10);
	root1->right = insert_tnode(80);
	root1->left->right = insert_tnode(20);
	root1->right->left = insert_tnode(60);
	root1->right->right = insert_tnode(90);

	cout << "print first tree:\n";
	print_in(root1);

	struct tnode* root2 = insert_tnode(50);
	root2->left = insert_tnode(20);
	root2->left->left = insert_tnode(15);
	root2->right = insert_tnode(110);
	root2->left->right = insert_tnode(30);
	root2->right->left = insert_tnode(100);
	root2->right->right = insert_tnode(120);
	cout << "\nprint second tree:\n";
	print_in(root2);

	struct tnode* root3 = insert_tnode(50);
	root3->left = insert_tnode(20);
	root3->left->left = insert_tnode(15);
	root3->right = insert_tnode(110);
	root3->left->right = insert_tnode(30);
	root3->right->left = insert_tnode(100);
	root3->right->right = insert_tnode(120);

	cout << "\nprint third tree:\n";
	print_in(root3);


	cout << "\nstatus of identical trees:";
	if (check_identical_trees(root1, root2))
		cout << "\ntrees are identical\n";
	else
		cout << "\ntrees are not identical\n";

	cout << "\nanother one\n";
	cout << "\nstatus of identical trees:";
	if (check_identical_trees(root2, root3))
		cout << "\ntrees are identical\n";
	else
		cout << "\ntrees are not identical\n";


	cout << "root to leaf node\n ";
	//char* path;

	root_to_leaf_paths(root1);
	std::cout << "\npaths for second tree\n";
	root_to_leaf_paths(root2);
	//cout << path;


	struct tnode* root4 = insert_tnode(50);
	root4->left = insert_tnode(20);
	root4->left->left = insert_tnode(15);
	root4->right = insert_tnode(110);
	root4->left->right = insert_tnode(30);
	root4->right->left = insert_tnode(100);
	root4->right->right = insert_tnode(120);
	root4->right->right->left = insert_tnode(115);
	root4->right->right->right = insert_tnode(140);

	std::cout << "\npaths for forth tree\n";
	root_to_leaf_paths(root4);

	cout << "print tree 4:\n";
	print_in(root4);
	cout << "\nprint level order \n";

	printLevelorder(root4);
}
#endif //TREE_MAIN





