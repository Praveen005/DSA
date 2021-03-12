#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
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
void print(node*head) {

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

}
int length(node* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

void insertAtHead(node* & head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node* n = new node(d);
	n->next = head;
	head = n;
}

void insertAtTail(node* &head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new node(d);
}

//p gives the position at which data is to be inserted
// p position means p-1 jumps
void insertAtMiddle(node* &head, int d, int p) {
	if (head == NULL || p == 0) {
		insertAtHead(head, d);
	}
	else if (p > length(head)) {
		insertAtTail(head, d);
	}
	else {
		node*temp = head;
		for (int i = 1; i < p; i++) {
			temp = temp->next;
		}
		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

node* takeInput() {
	int d;
	cin >> d;
	node*head = NULL;
	while (d != -1) {
		// insertAtTail(head, d);
		insertAtHead(head, d);
		cin >> d;
	}
	return head;
}

istream& operator>>(istream &is, node* &head) {
	head = takeInput();
	return cin;
}
ostream& operator<<(ostream& os, node*head) {
	print(head);
	cout << endl;
	return os;
}
// now we will delete a node and then reverse a linked list iteratively

void deleteHead(node*&head) {
	if (head == NULL) {
		return;
	}
	node*temp = head->next;
	delete head;
	head = temp;
}
void deleteTail(node*&head) {
	if (head == NULL) {
		return;
	}
	if (length(head) == 1) {
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
//reverse the linked list iteratively
void reverse(node*&head) {
	if (head == NULL) {
		return;
	}
	//p- previous, c- current, n- next
	node* p;
	node* c;
	node* n;
	p = NULL;
	c = head;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}


//position p denotes that we have to delete the node at the position 'p'
void deleteAtMiddle(node*&head, int p) {
	if (head == NULL || p == 0) {
		deleteHead(head);
		return;
	}
	else if (p > length(head)) {
		deleteTail(head);
	}
	else {
		node*temp = head;
		for (int i = 1; i < p - 1; i++) {
			temp = temp->next;
		}
		node*n = temp->next->next;
		delete temp->next;
		temp->next = n;
	}

}

// Reverese the linked list recursively
// O(N^2) - time complexity

/*node* recReverse(node*head) {
	if (head->next == NULL || head == NULL) {
		return head;
	}

	node*shead = recReverse(head->next);
	node*temp = shead;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return shead;
}*/
// O(N) - time complexity
node* recReverse(node*head) {
	if (head->next == NULL || head == NULL) {
		return head;
	}
	node*shead = recReverse(head->next);
	// node*temp = head->next;
	//or

	head->next->next = head;
	//temp->next = head;
	head->next = NULL;
	return shead;
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
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtTail(head, 8);
	insertAtTail(head, 10);
	insertAtMiddle(head, 7, 6);
	insertAtMiddle(head, 9, 8);
	print(head);
	cout << endl;

	node*head1 = NULL;
	cin >> head1;
	cout << head1;
	cout << "length of the linked list : " << length(head) << endl;
	deleteHead(head);
	cout << head;
	deleteAtMiddle(head, 3);
	cout << head;
	deleteTail(head);
	cout << head;
	cout << "\n\n";
	insertAtTail(head, 89);
	reverse(head);
	print(head);
	cout << endl;
	head = recReverse(head);
	cout << head;



}
