//'ll print a \n after every level
// 2 methods.
#include <iostream>
#include<queue>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;

	//constructor
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Building the tree

node* BuildTree(void) {    // This function returns the address to the root node
	int d; cin >> d;
	//Base case
	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = BuildTree();
	root->right = BuildTree();
	return root;
}

//Method - I  : storing the value of every level along with node in the queue
void bfs(node* root) {
	//form variable of type pair<node*,int> and push it to the queue
	pair<node*, int>p, temp;
	queue<pair<node*, int>> q;
	int j = 1;
	p = make_pair(root, j);
	q.push(p);


	while (!q.empty()) {
		temp = q.front();
		j = temp.second;
		node* f = temp.first;
		cout << f->data << " ";
		q.pop();
		if (f->left) { //if left child is not NULL
			p = make_pair(f->left, j + 1);
			q.push(p);
		}

		if (f->right) { //similarly if the right child exists
			p = make_pair(f->right, j + 1);
			q.push(p);
		}


		/*
			print '\n' if the level(temp.second)[after popping] is different
			than the previous node.
		*/
		temp = q.front();
		if (temp.second != j and !q.empty()) {
			cout << endl;
		}
	}
	return;

}


//Method - II

void bfs2(node* root) {
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	while (!Q.empty()) {
		node* f = Q.front();
		if (f == NULL) {
			Q.pop();
			if (!Q.empty()) { //if u don't use this if(), u 'll get an infinite loop
				Q.push(NULL);
				cout << '\n';
			}
		}
		else {
			cout << f->data << " ";
			Q.pop();
			if (f->left) { //if left child is not NULL
				Q.push(f->left);
			}
			if (f->right) { //similarly if the right child exists
				Q.push(f->right);
			}
		}
	}
	return;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* root = BuildTree();
	bfs(root);
	cout << "\n\n";
	bfs2(root);
	return 0;
}



