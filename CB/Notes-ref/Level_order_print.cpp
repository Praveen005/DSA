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

int height(node* root){
    if(root== NULL){
        return 0;
    }

    int lsh=height(root->left);   //height of left subtree
    int rsh=height(root->right); //Right subtree height

    return max(lsh, rsh)+1;
}

void PrintKthLevel(node* root, int k){
    // Base case
    if(root==NULL){
        return;
    }
    if(k==1){  //k=1 means we are at the right node.
        cout<<root->data<<" ";
        return;
    }

    PrintKthLevel(root->left, k-1);
    PrintKthLevel(root->right, k-1);
    return;

}

void PrintAllLevels(node* root){
    int H=height(root);
    for(int i=1; i<=H; i++){
        PrintKthLevel(root, i);
        cout<<endl;
    }
    return;
}
int main() {
    node* root=BuildTree();
    /*
    printPre(root);
    cout<<endl;
    printPost(root);
    cout<<endl;

    printIn(root);
    cout<<endl;
    */
    /*
    cout<<"height: ";
    int h=height(root);
    cout<<h<<endl;
    */

    PrintAllLevels(root);
    return 0;
}


/*

worst case time complexity: O(N2)

*/

