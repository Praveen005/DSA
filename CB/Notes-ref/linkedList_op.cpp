#include<iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void InsertAtHead(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}

	node*n = new node(d);
	n->next = head;
	head = n;
}

// keep taking input till you encounter -1
node* takeInput() {
	node*head = NULL;
	int d;
	cin >> d;
	// while (cin >> d) {
	while (d != -1) {
		InsertAtHead(head, d);
		cin >> d;
	}
	return head;
}

void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

//operator overloading
template<class ostream, class T>
ostream& operator<<(ostream &os, T head) {
	print(head);
	return cout;
}

//here we are taking head by reference because we want the value returned by the
//takeInput() function updated to the head

istream& operator>>(istream &is, node* &head) {
	head = takeInput();
	return is;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* head = takeInput();
	print(head);
	cout << endl;

	node*head1 = NULL;
	node* head2 = NULL;

	cin >> head1 >> head2;

	cout << "2nd output:   ";
	cout << head1 << endl;
	cout << "3rd output:  ";
	cout << head2 << endl;
}