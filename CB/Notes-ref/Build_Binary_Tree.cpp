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

void print(node* root){ 
    //Base case
    if(root==NULL){
        return;
    }
    //print root, followed by subtree(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main() {
    node* root=BuildTree();
    print(root);
    return 0;
}

