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
void append(node* & head, int k) {
	node* fast = head;
	node* slow = head;
	for (int i = 1; i < num; i++) {
		if (i < k) {
			fast = fast->next;
		}
		else {
			fast = fast->next;
			if (fast->next != NULL)
				slow = slow->next;
		}
	}

	fast->next = head;

	head = slow->next;
	slow->next = NULL;
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> num;
	node* head = NULL;
	cin >> head;
	int k; cin >> k;
	k = k % num; // question says 'k' can be greater than 'num'
	if ( k != 0) 			// k = 0 then you don't need to do anything
		append(head, k);
	print(head);
	return 0;
}



