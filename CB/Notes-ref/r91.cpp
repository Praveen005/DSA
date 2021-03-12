#include<iostream>
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
void print(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return;
}
void insertAtHead(node* & head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node* temp = new node(d);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(node* head, int d) {
	if (head == NULL) {
		insertAtHead(head, d);
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	node* temp2 = new node(d);
	temp->next = temp2;
	return;

}
int length(node* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}
//position starts from 0
void insertInMiddle(node* &head, int d, int position) {
	if (position == 0 || head == NULL) {
		insertAtHead(head, d);
		return;
	}
	if (position > length(head)) {
		insertAtTail(head, d);
		return;
	}
	else {
		node* temp = head;
		for (int i = 1; i < position; i++) {
			temp = temp->next;
		}
		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;

	}
}

void deleteAtHead(node*&head) {
	if (head == NULL) {
		return;
	}
	node* temp = head->next;

	delete  head;
	head = temp;

}

void deleteTail(node* &head) {
	if (head == NULL) {
		return;
	}
	// node* temp=head;
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;

	}
	delete temp->next;
	temp->next = NULL;
}

void deleteMiddle(node*&head, int position) {
	if (head == NULL || position == 0) {
		deleteAtHead(head);
		return;
	}
	if (position >= length(head)) {
		deleteTail(head);
		return;
	}
	node* temp = head;
	for (int i = 0; i < position - 1; i++) {
		temp = temp->next;
	}
	node* n = temp->next->next;
	delete temp->next;
	temp->next = n;
}

//following is the iterative approach to get the key
bool search(node* head, int key) {
	while (head != NULL) {
		if (head->data == key) {
			return true;
		}
		head = head->next;
	}
	return false;

}
//recursive
bool recSearch(node* head, int key) {
	if (head == NULL) {
		return false;
	}
	if (head->data == key) {
		return true;
	}
	return recSearch(head->next, key);
}


node* takeInput() {
	node* head = NULL;

	int data;
	int n;
	cin >> n;

	while (n--) {
		cin >> data;
		insertAtHead(head, data);

	}
	return head;
}
istream& operator>>(istream& is, node* &head) {
	head = takeInput();
	return is;
}

ostream& operator<<(ostream& os, node* head) {
	print(head);
	return os;
}

// THIS WAS AN ITERATIVE APPROACH TO REVERSE THE LINKED LIST
void reverse(node*&head) {
	node* prev = NULL;
	node* current = head;
	node* Next = NULL;

	while (current != NULL) {
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;
	}
	head = prev;
}

// recursively reversing the linked list
node* RecursiveReverse(node* head) {
	//base case

	if (head->next == NULL || head == NULL) {
		return head;
	}
	node* shead = RecursiveReverse(head->next);
	// node* temp = shead;
	// while (temp->next != NULL) {
	// 	temp = temp->next;
	// }

	// temp->next = head;
	// head->next = NULL;
	head->next->next = head;
	head->next = NULL;
	return shead;
}

node* mid(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	node* slow = head;
	node* fast = head->next;
	// int count = 0;
	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node* KthFromEnd(node* head, int k) {
	if (head == NULL) {
		return head;
	}
	node* fast = head;
	node* slow = head;
	int count = 0;
	while (fast != NULL) {
		if (count < k) {
			fast = fast->next;
		}
		else {
			slow = slow->next;
			fast = fast->next;
		}
		count++;
	}
	return slow;
}

node* merge(node* head, node* head2) {
	if (head == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head;
	}
	node* c = NULL;
	if (head->data < head2->data) {
		c = head;
		c->next = merge(head->next, head2);
	}
	else {
		c = head2;
		c->next = merge(head, head2->next);
	}
	return c;
}

node* mergeSort(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	node* midNode = mid(head);
	node* b = midNode->next;
	midNode->next = NULL;
	// print(head);
	// print(b);

	head = mergeSort(head);
	b = mergeSort(b);


	node* result = merge(head, b);

	return result;
}

bool detectCycle(node* head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}
	node* slow = head;
	node* fast = head;

	while (fast  != NULL && fast->next != NULL ) {
		slow = slow->next;
		fast = fast->next->next;
		// cout << slow->data << "  " << fast->data << endl;
		if (fast == slow) {
			fast = head;
			while (fast->next != slow->next) {
				slow = slow->next;
				fast = fast->next;
				if (fast->next == slow->next) {
					cout << fast->next->data << endl;
					return true;
				}
				// cout << 1;
			}
		}


	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//revising the linked list

	node* head = NULL;
	insertAtHead(head, 1);
	node* s = head;
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 5);
	node* e = head;
	insertAtHead(head, 6);
	insertAtHead(head, 7);
	insertAtHead(head, 8);
	print(head);


	s->next = e;
	// print(head);

	// we will use floyd's cycle method to detect a cycle in the linked list

	if (detectCycle(head)) {
		cout << "CYCLE\n";
	}
	else {
		cout << "NO cycle\n";
	}





}