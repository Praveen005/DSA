#include<iostream>
#include<forward_list>
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
	int d;
	while (cin >> d) {
		insertAtTail(head, d);
	}
	return head;
}

istream& operator>>(istream& is, node* &head) {
	head = takeInput();
	return is;
}

void print(node* head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void insertion_sort(node*& head) {
	if (head == NULL || head->next == NULL) {
		return ;
	}
	node* permanent = head;
	node* cur = head->next;
	while (cur != NULL) {
		permanent = head;
		while (permanent != cur) {
			if (permanent->data >= cur->data) {
				int value = cur->data;
				cur->data = permanent->data;
				permanent->data = value;
			}
			permanent = permanent->next;
		}
		cur = cur->next;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	node* head = NULL;
	cin >> head;
	print(head);

	insertion_sort(head);
	print(head);

}


