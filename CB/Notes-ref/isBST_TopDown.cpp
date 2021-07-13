// Check if the given tree is a BST

#include <iostream>
#include<climits>
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

node* BuildTree(void){
    int d; cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}

//bfs
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

//Checking if the current tree is a BST: TopDown approach
bool iS_BST(node* root, int minv=INT_MIN , int maxv=INT_MAX){
    if(root==NULL){
        return true;
    }

    if(root->data>minv and root->data<maxv and iS_BST(root->left, minv, root->data) and iS_BST(root->right, root->data, maxv)){
        return true;
    }
    return false;
}


int main() {
    node* root=BuildTree();
    bfs(root);
   

    if(iS_BST(root)){
        cout<<"YES";
    }
    else{
        cout<<"Not a BST!\n";
    }
}

/*

Sample Input:
8 6 3 -1 -1 7 -1 -1 16 -1 -1

sample output:
8,
6,16,
3,7,
YES






--------------------------------------

sample input: 
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1


sample output:

1,
2,3,
4,5,
6,7,8,9,
10,11,
Not a BST!


*/

