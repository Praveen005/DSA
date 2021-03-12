//Revising Linked list
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};
void insertAtTail(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	node*temp = new node(d);
	tail->next = temp;
}

void insertAtHead(node* &head, int n) {
	if (head == NULL) {
		head = new node(n);

		return;
	}
	else {
		node* temp = new node(n);
		temp->next = head;
		head = temp;
	}
}
int length(node*head) {
	int count = 0;

	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}
void insertAtMiddle(node* &head, int d, int p) {
	// p position means  p-1 jumps
	if (head == NULL || p == 0) {
		head = new node(d);
		return;
	}
	else if (p > length(head)) {
		insertAtTail(head, d);
	}
	else {
		//jump p-1 times
		node*n = head;
		for (int i = 1; i < p; i++) {
			n = n->next;
		}
		node*temp = new node(d);
		temp->next = n->next;
		n->next = temp;
	}
}
void print(node*head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;

	}
	cout << endl;
}

// now we will delete the nodes
void deleteHead(node* &head) {
	if (head == NULL) {
		return;
	}

	node*temp = head->next;
	delete head;
	head = temp;

}
void deleteTail(node* &head) {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	node*temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}
void deleteMiddle(node* &head, int p) {
	if (head == NULL || p == 0) {
		return;
	}
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	/// we need to n-2 jumps to delete the node required
	node*temp = head;
	for (int i = 1; i < p - 1; i++) {
		temp = temp->next;
	}
	node*n = temp->next->next;
	delete temp->next;
	temp->next = n;

}
node* takeInput(void) {
	int d;
	cin >> d;
	node* head = NULL;
	while (d != -1) {
		insertAtHead(head, d);
		cin >> d;
	}
	return head;
}
//overloading the input and output operator
ostream& operator<<(ostream &os ,  node* head) {
	print(head);
	return os;
}

istream& operator>>(istream& is , node* &head) {
	head = takeInput();
	return is;
}
bool isPresent(node* head, int key) {
	if (head == NULL) {
		return false;
	}
	if (head->data == key) {
		return true;
	}
	isPresent(head->next, key);
}

// will reverse a linked list
void reverse(node* &head) {
	if (head == NULL || head->next == NULL) {
		return;
	}
	node*p = NULL;
	node* c = head;
	node*N;
	while (c != NULL) {
		N = c->next;
		// node*temp = c;
		c->next = p;
		// p = temp;
		p = c;
		c = N;

	}
	head = p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	insertAtHead(head, 9);
	insertAtHead(head, 8);
	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	print(head);
	node* head1 = NULL;
	cin >> head1;
	print(head1);
	reverse(head1);
	print(head1);
	deleteMiddle(head, 1);

}