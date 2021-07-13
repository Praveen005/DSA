/*
	Flatten the  tree

	BST to a Sorted linked list

*/
#include<iostream>
#include<climits>
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

class LinkedList {
public:
    node* head;
    node* tail;
};

LinkedList flatten(node* root) {
    LinkedList l;
    if (root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }

    //Leaf node

    if (root->left == NULL and root->right == NULL) {
        l.head = l.tail = root;
        return l;
    }

    //if right subtree doesn't exist
    if (root->left != NULL and root->right == NULL) {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    //if left subtree doesn't exist
    if (root->right != NULL and root->left == NULL) {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        l.tail = rightLL.tail;
        l.head = root;
        return l;
    }

    //if both the subtrees exist

    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main() {

    node* root = BuildTree();
    bfs(root);
    cout << endl;
    cout << endl;

    LinkedList l = flatten(root);

    node* temp = l.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

}

/*

sample input:
5 3 7 1 6 8 -1


sample output:

5 
3 7 
1 6 8 

1 3 5 6 7 8





*/
