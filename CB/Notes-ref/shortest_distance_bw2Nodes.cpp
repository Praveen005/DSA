/*

Shortest distance between two given nodes of a binary tree


*/

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

//Following function will build a binary tree not a BST
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
    // int k=0;

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        if(f==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
            }
        }
        else{
           
            cout<<f->data<<" ";

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
//we are assuming that nodes whose LCA is being found out is present in the tree
// every entry is unique

node* LCA(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==a || root->data==b){
        return root;
    }

    node* leftans=LCA(root->left, a, b);
    node* rightans=LCA(root->right, a, b);
    if(leftans && rightans){
        return root;
    }
    if(leftans){
        return leftans;
    }
    return rightans;
}

//Search() will give the distance between 2 nodes in one branch
int search(node* root, int key, int level){
    if(root==NULL){
        return -1;
    }

    if(root->data==key){
        return level;
    }
    int k= search(root->left, key,level+1);
    if(k !=-1){
        return k;
    }
    return search(root->right, key, level+1);

}

int findDistance(node* root, int a, int b){
    if(root==NULL){
        return -1;
    }

    node* lca=LCA(root, a, b);
    int l1=search(lca, a,0);
    int l2=search(lca, b, 0);
    
    return l1+l2;
}

int main() {


    node* root = BuildTree();
    bfs(root);
    cout << endl;
    int a, b; cin>>a>>b;
    cout<<"Distance: ";
    cout<<findDistance(root, a, b)<<endl;

 
}

/*


sample input: 
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
11 3


sample output:

1 
2 3 
4 5 
6 7 8 9 
10 11 
Distance: 5

*/
