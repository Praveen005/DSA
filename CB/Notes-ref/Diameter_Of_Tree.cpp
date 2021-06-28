#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root) {
    if (root == NULL) {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void printIn(node*root) {
    if (root == NULL) {
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPost(node*root) {
    if (root == NULL) {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

int height(node*root) {
    if (root == NULL) {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;

}

void printKthLevel(node*root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;

}

void printAllLevels(node*root) {
    int H = height(root);

    for (int i = 1; i <= H; i++) {
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

int count(node*root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* f = q.front();
        if (f == NULL) {
            cout << endl;
            q.pop();
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << f->data << ",";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    return;
}

void mirror(node*root) {
    if (root == NULL) {
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}
//O(N2) approach
int Diameter(node* root) {
    if (root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int option1 = h1 + h2;
    int option2 = Diameter(root->left);
    int option3 = Diameter(root->right);
    return max(option1, max(option2, option3));
}
//Optimised approach of finding the diameter of the tree
//Time-complexity: O(N);
class Pair {
public:
    int height;
    int diameter;
};

//Finding the diameter of the tree
Pair fastDiameter(node* root) {
    Pair p;
    //Base case
    if (root == NULL) {

        p.height = p.diameter = 0;
        return p;

    }

    //otherwise
    //left & right waale child ka height, diameter bataiye
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    //now we have the diameter and height of the children of the current node
    //now we can find out the height and the diameter of the current node
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;


}


int main() {
/*

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

*/
    node* root = buildTree();
    //cout<<count(root)<<endl;
    //printAllLevels(root);
    cout << "Diameter[O(N2)]: " << Diameter(root) << endl;
    Pair p = fastDiameter(root);
    cout << "Height: " << p.height << endl;
    cout << "Diameter[O(N)]: " << p.diameter << endl;

    return 0;
}

/*

sample input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

sample output: 

Diameter[O(N2)]: 6
Height: 4
Diameter[O(N)]: 6


*/
