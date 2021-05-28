#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};

//Building the tree

node* BuildTree(void){     // This function returns the address to the root node
    int d; cin>>d;
    //Base case
    if(d ==-1){
        return NULL;
    }

    node* root= new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}

//Preorder print
void printPre(node* root){ 
    //Base case
    if(root==NULL){
        return;
    }
    //print root, followed by subtree(children)
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}


//Inorder print
void printIn(node* root){ 
    //Base case
    if(root==NULL){
        return;
    }
    //print root, followed by subtree(children)
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

//Postorder 
void printPost(node* root){ 
    //Base case
    if(root==NULL){
        return;
    }
    //print root, followed by subtree(children)
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
int main() {
    node* root=BuildTree();
    printPre(root);
    cout<<endl;
    printPost(root);
    cout<<endl;

    printIn(root);

    return 0;
}


/*

Input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1


Output: 
8 10 1 6 9 7 3 14 13 
1 9 7 6 10 13 14 3 8 
1 10 9 6 7 8 3 13 14 

*/

