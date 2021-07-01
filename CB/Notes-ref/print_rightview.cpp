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

void PrintRightView(node* root, int level, int &maxlevel) {
    if (root == NULL) {
        return;
    }

    if (level > maxlevel) {
        cout << root->data << " ";
        maxlevel = level;
    }

    //Traverse the side subtree
    PrintRightView(root->right, level + 1, maxlevel);

    //traverse the left subtree
    PrintRightView(root->left, level + 1, maxlevel);
}

//Aliter
/*
void PrintRightViewBFS(node* root) {
    pair<node*, int>p, s, r;
    p = make_pair(root, 0);

    queue<pair<node*, int>>q;
    q.push(p);
    int k;
    while (!q.empty()) {
        s = q.front();
        node* temp = s.first;
        k = s.second;
        q.pop();
        if (!q.empty()) {
            r = q.front();
            int k1 = r.second;
            if (k != k1) {
                cout << temp->data << " ";
            }
        }
        else {
            cout << temp->data << " ";
        }
        if (temp->left) {
            r = make_pair(temp->left, k + 1);
            q.push(r);
        }
        if (temp->right) {
            r = make_pair(temp->right, k + 1);
            q.push(r);
        }
    }
}
*/

int main() {
/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
*/
    node* root = BuildTree();
    BFS(root);
    // PrintRightViewBFS(root);
    int maxlevel = -1;
    cout << "\n\nRight view of the tree: ";
    PrintRightView(root, 0, maxlevel);
}

/*

sample Input1:
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
sample output:
1 
2 3 
4 5 
6 7 8 9 
10 11 

Right view: 1 3 5 9 11 





sample input2: 
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

sample output:
8 
10 3 
1 6 14 
9 7 13 

Right view: 8 3 14 13 

*/

