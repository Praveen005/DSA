#include <iostream>
#include<queue>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;

	//constructor
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Building the tree

node* BuildTree(void) {    // This function returns the address to the root node
	int d; cin >> d;
	//Base case
	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = BuildTree();
	root->right = BuildTree();
	return root;
}

int NumberOfNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+ NumberOfNodes(root->left) + NumberOfNodes(root->right);
}

int SumOfNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return root->data + SumOfNodes(root->left) + SumOfNodes(root->right);
}


int main() {

	node* root = BuildTree();
	cout<<NumberOfNodes(root)<<endl;
	cout<<SumOfNodes(root);

	return 0;
}



