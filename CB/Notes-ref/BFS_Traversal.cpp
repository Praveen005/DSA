#include <iostream>
#include<queue>
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

void bfs(node* root){
    queue<node*> Q;
    Q.push(root);

    while(!Q.empty()){
        node* f = Q.front();
        cout<<f->data<<" ";
        Q.pop();
        if(f->left){  //if left child is not NULL
            Q.push(f->left);
        }
        if(f->right){ //similarly if the right child exists
            Q.push(f->right);
        }
    }
    return;
    
}
int main() {
    node* root=BuildTree();
    bfs(root);
    return 0;
}

