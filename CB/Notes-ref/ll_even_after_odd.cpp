#include<iostream>
using namespace std;
int num;
class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};
void insertAtTail(node* & head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;

	}
	node* n = new node(d);
	temp->next = n;
}
node* takeInput(void) {
	node* head = NULL;
	for (int i = 0; i < num; i++) {
		int d;
		cin >> d;
		insertAtTail(head, d);
	}
	return head;
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
istream& operator>>(istream& is, node* &head) {

	head = takeInput();
	return is;
}

ostream& operator<<(ostream& os, node* head) {
	print(head);
	cout << endl;
	return os;
}

node* reverse(node* head , int k) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	node* p = NULL;
	node* c = head;
	node* N;
	for (int i = 1; i <= k; i++) {
		N = c->next;
		c->next = p;
		p = c;
		c = N;
	}

	if (c != NULL) {
		head->next = reverse(c, k);
	}
	return p;

}
void deleteHead(node* & head) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
}
void deleteTail(node* &head) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	if (temp->next == NULL) {
		delete temp;
		head = NULL;
	}
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

	else {
		node* temp = head;
		for (int i = 1; i < p - 1; i++) {
			temp = temp->next;
		}
		node* n = temp->next->next;
		delete temp->next;
		temp->next = n;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> num;
	node* head = NULL;
	cin >> head;

	node* head1 = NULL;
	int count = 1;
	node* temp = head;


	while (temp != NULL) {
		int n = temp->data;
		temp = temp->next;
		if (n % 2 != 0) {
			insertAtTail(head1, n);
			if (count == 1) {
				deleteHead(head);
			}
			else
				deleteMiddle(head, count);
			count--;
		}
		count++;


	}

	temp = head1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	print(head1);

}
