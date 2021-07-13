//form the BST from its given preorder traversal

#include<iostream>
#include<algorithm>
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


class Solution {
public:
//You can just make 'i' a public variable and remove static declaration if you get runtime error, like on leetcode
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
    // int i=0;
    node* buildTree(vector<int>& pre, vector<int> ino, int s, int e) {
        if (s > e) {
            return NULL;
        }
        static int i = 0;
        node* root = new node(pre[i]);
        //now we will search for the node with value pre[i] in the inorder
        int index = -1;

        for (int j = s; j <= e; j++) {
            if (ino[j] == pre[i]) {
                index = j;
                break;
            }
        }
        i++;

        root->left = buildTree(pre, ino, s , index - 1);
        root->right = buildTree(pre, ino, index + 1, e);
        return root;
    }



    node* bstFromPreorder(vector<int>& preorder) {
        vector<int>v = preorder;
        sort(v.begin(), v.end());

        node* ans = buildTree(preorder, v, 0, preorder.size() - 1);

        return ans;
    }
};




int main() {

    vector<int>v({5, 3, 1, 7, 6, 8});

    Solution sol;

    node* ans = sol.bstFromPreorder(v);
    bfs(ans);

}


/*

sample input:
5 3 7 1 6 8 -1


sample output:
5 
3 7 
1 6 8

*/
