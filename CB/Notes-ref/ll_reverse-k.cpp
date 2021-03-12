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
		/*
		YAHAN HEAD->NEXT KARNA JARURI HAI, KYUN KI abhi wale head ko aage wale sub -linked list
		ke reverse wale ke first element ko pint karna hai.
		ek baari copy pe p, cN likh kar reverse karke dry run karo  saara clear
		ho jaayega.
		*/
		head->next = reverse(c, k);
	}
	return p;

}
int main() {

	cin >> num;
	int k; cin >> k;
	node* head = NULL;
	cin >> head;

	head = reverse(head, k);
	print(head);


}

