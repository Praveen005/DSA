#include<iostream>
using namespace std;

// Defined the node class
class node {
public:
	int data;
	node* next;

	// constructor
	node(int d): data(d) {
		next = NULL;
	}
};

//print the node
// Passing by value and not by reference because we don't want to make changes in the original
// 'head' pointer
void print(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// getting the length of the linked list
int length(node*head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

// Insert at the head

void InsertAtHead(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node* n = new node(d);
	n -> next = head;
	head = n;
}


/*
	ek baat yaad rakhen jab bhi head ke alawe kahin aur se insert karen to
	head ka ek copy bana len
	head ka ek particular position hota hai, use tab tak disturb na kare jab tak
	head ke through insertion na karna ho.

	golden rule: make a copy of the head pointer, kyun ki
	insertion function me head by reference aa raha.



*/

// Insert at the tail
void InsertAtTail(node* &head, int d) {

	// cornor case
	if (head == NULL) {
		head = new node(d);
		return;
	}
	// here you see, you have the head and not the pointer to tail
	// so you will first reach to the tail and then insert the data
	//repeating again, you are currently at the head
	// we have now created a copy of the head pointer
	node*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	// now you are pointing at the tail
	// now we will create a new node and attach it at the end
	tail->next = new node(d);
	return;
}

void InsertAtMiddle(node* &head, int d, int p) {

	if (head == NULL || p == 0) {
		InsertAtHead(head, d);
	}

	else if (p > length(head)) {
		InsertAtTail(head, d);
	}
	else {
		// At position p means we have  to make p-1 jumps
		node*temp = head;
		for (int i = 0; i < p - 1; i++) {
			temp = temp -> next;
		}
		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	node* head = NULL;
	InsertAtHead(head, 5);
	InsertAtHead(head, 1);
	InsertAtHead(head, 2);
	InsertAtHead(head, 3);
	InsertAtHead(head, 4);

	// print the Linked List

	print(head);
	cout << endl;
	InsertAtTail(head, 56);
	print(head);
	cout << endl;

	InsertAtMiddle(head, 99, 2);
	print(head);

}