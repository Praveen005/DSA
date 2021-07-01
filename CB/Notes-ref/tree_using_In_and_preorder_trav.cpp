//Build a tree given its Inorder and preorder traversal



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

node* BuildTree(void) {
    int d; cin >> d;
    if (d == -1) {
        return NULL;
    }

    node* root = new node(d);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}
void BFS(node* root) {
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

int ReplaceNodes(node*& root) {
    //BASE CASE

    if (root == NULL) {
        return 0;
    }
    //we have to leave the leaf nodes unchanged
    if (root->left == NULL and root->right == NULL) {
        return root->data;
    }

    int leftsum = ReplaceNodes(root->left);
    int rightsum = ReplaceNodes(root->right);
    int temp = root->data;
    root->data = leftsum + rightsum;
    return root->data + temp;
}

//you can use the inbuilt pair class
class HBpair {
public:
    int height;
    bool balance;
};

HBpair isHeightBalanced(node* root) {
    HBpair p;
    //BASE CASE
    if (root == NULL) {
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBpair left = isHeightBalanced(root->left);
    HBpair right = isHeightBalanced(root->right);
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 and left.balance and right.balance) {
        p.balance = true;
    }
    else {
        p.balance = false;
    }
    return p;

}

node* BuildBalancedTree(int*a, int s, int e) {
    //BASE CASE
    if (s > e) {
        return NULL;
    }

    //Recursive case
    int mid = (s + e) / 2;
    node* root = new node(a[mid]);
    root->left = BuildBalancedTree(a, s, mid - 1);
    root->right = BuildBalancedTree(a, mid + 1, e);
    return root;


}
node* BuildUsinfTrav(int*in, int* pre, int s, int e) {
    //base case
    if (s > e) {
        return NULL;
    }

    static int j = 0;
    int val = pre[j];
    //linear search
    int index = -1;
    for (int i = s; i <= e; i++) {
        if (in[i] == val) {
            index = i;
            break;
        }
    }
    j++;
    node* root = new node(in[index]);
    root->left = BuildUsinfTrav(in, pre, s, index - 1);
    root->right = BuildUsinfTrav(in, pre, index + 1, e);
    return root;

}

int main() {
/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT

*/
    /*
    node* root = BuildTree();
    BFS(root);

    //problem

    //replace each node with the sum of its child nodes

    ReplaceNodes(root);
    cout << "\n\n";
    BFS(root);

    //A tree is said to be balanced if the absolute value of the height of the
    // and the right subtree is <= 1
    cout << endl;
    if (isHeightBalanced(root).balance) {
        cout << "The tree is balanced\n";
    }
    else {
        cout << "The tree is not balanced\n";
    }

    */

    //let's build a height balanced tree from given array
    // int n; cin >> n;
    // int a[100];
    // for (int i = 0; i < n ; i++) {
    //     cin >> a[i];
    // }

    // node* root = BuildBalancedTree(a, 0, n - 1);
    // BFS(root);

    int inorder[] = {3, 2 , 8, 4, 1, 6, 7, 5};
    int preorder[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(preorder) / sizeof(int);
    node* root = BuildUsinfTrav(inorder, preorder, 0, n - 1);
    BFS(root);
}


/*

output:
1 
2 5 
3 4 6 
8 7




*/
