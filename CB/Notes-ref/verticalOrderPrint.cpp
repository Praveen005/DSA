#include <iostream>
#include<vector>
#include<map>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;

    //constructor
    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }
};
//passing the map by reference
void verticalOrderPrint(node* root, int d, map<int, vector<int>>&verticalOrder){
    if(root==NULL){
        return;
    }
    verticalOrder[d].push_back(root->data);

    verticalOrderPrint(root->left, d-1, verticalOrder);
    verticalOrderPrint(root->right, d+1, verticalOrder);
    return;
}
int main() {
    node* root=new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);

    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right=new node(7);

    root->right->right->right= new node(8);
    root->left->right->right= new node(9);
    int d=0;
    map<int, vector<int>>verticalOrder;
    verticalOrderPrint(root, d, verticalOrder);

    for(auto s:verticalOrder){
        for(int x:s.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

/*
output:
4 
2 
1 5 6 
9 3 
7 
8 

*/

*/

