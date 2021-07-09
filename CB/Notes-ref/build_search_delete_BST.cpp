#include<iostream>
#include<queue>
using namespace std;
#define ll long long

#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

class node {
public:
    int data;
    node* left;
    node* right;
    // constructor
    node(int d) {
        data = d;
        right = NULL;
        left = NULL;
    }
};

//Building the BST
node* InsertInBST(node* root, int d) {
    if (root == NULL) {
        return new node(d);
    }
    if (d <= root->data) {
        root->left = InsertInBST(root->left, d);
    }
    else {
        root->right = InsertInBST(root->right, d);
    }
    return root;
}
node* BuildTree(void) {
    int d; cin >> d;
    node* root = NULL;
    while (d != -1) {
        root = InsertInBST(root, d);
        cin >> d;
    }
    return root;
}

//Printing the Binary Search Tree level wise
//bfs
void bfs(node* root) {
    if (root == NULL) {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}


//in-order print of the BST
//Remember: the in-order print of a BST will give you the elements of the BST
//in sorted manner
void inorderPrint(node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

//searching an element in the BST
bool search(node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    else if (key == root->data) {
        return true;
    }
    else {
        return search(root->right, key);
    }
}

//Deletion of a node from the BST

node* deleteInBST(node*root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (data < root->data) {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if (data == root->data) {
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        //3. Case 2 children
        node *replace = root->right;
        //Find the in-order successor from right subtree
        while (replace->left != NULL) {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT

    node* root = BuildTree();
    cout << "BFS Print: \n";
    bfs(root);
    cout << "\n\n";
    cout << "In-order print:\n";
    inorderPrint(root);
    cout << endl;


    int s;
    cin >> s;


    cout << "\n\n--------After Deletion-----------\n\n";

    root = deleteInBST(root, s);
    cout << "BFS Print: \n";
    bfs(root);
    cout << "\n\n";
    cout << "In-order print:\n";
    inorderPrint(root);
    cout << endl;


}

/*

sample Input: 
5 3 7 1 6 8 -1
5


sample output:
BFS Print: 
5 
3 7 
1 6 8 

In-order print:
1 3 5 6 7 8 


--------After Deletion-----------

BFS Print: 
6 
3 7 
1 8 

In-order print:
1 3 6 7 8 

*/
