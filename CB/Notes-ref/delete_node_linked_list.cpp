#include <iostream>
#include<climits>
using namespace std;

class node {
public:
    int data;
    node*next;

    //constructor

    node(int d) {
        data = d;
        next = NULL;
    }
};
// now will insert the data

void print(node*head) {
    while (head != NULL) {
        cout << head->data << "  ";
        head = head->next;
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
void insertAtHead(node* &head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node* &head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    // make a copy of the head pointer and move it to the last node
    node*tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(d);
}
void insertInMiddle(node* &head, int d, int p) {
    if (head == NULL || p == 0) {
        insertAtHead(head, d);

    }
    else if (p > length(head)) {
        insertAtTail(head, d);
    }
    else {
        //we created a copy of head, since are required to insert an element in the middle
        node*temp = head;
        // nowwe need to take p-1 jumps

        for (int i = 1; i < p; i++) {
            temp = temp->next;
        }
        node*n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }

}

void deleteFromHead(node* &head) {
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

    node*temp = head;
    int n = length(head);
    if (n == 1) {
        head = NULL;
        return;
    }
    for (int i = 1; i <= n - 2; i++) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

}



// This function is also kargar/working
// void deleteTail(node* &head) {
//     if (head == NULL) {
//         return;
//     }
//     node*temp = head;
//     if (temp->next == NULL) {
//         delete temp;
//         head = NULL;
//         return;
//     }

//     while (temp->next->next != NULL) {
//         temp = temp->next;
//     }
//     delete temp->next;
//     temp->next = NULL;

// }

void deleteFromMiddle(node* &head, int p) {
    if (head == NULL || p == 0) {
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
        node* temp1 = temp->next;
        temp -> next = temp->next->next;
        delete temp1;
    }
}

//agar hum search function me head agar
// by reference pass karenge tab hum ek copy bana lenge head ka
// but hum yahan pe by value pass kar rahe hain
bool search(node*head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// Recursive approach to search the element

bool searchRecursive(node*head, int key) {
    if (head == NULL) {
        return false;
    }
    if (head->data == key) {
        return true;
    }
    else {
        searchRecursive(head->next, key);
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

    node*head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    print(head);
    cout << endl;
    insertAtTail(head, 88);
    // insertAtTail(head, 89);
    // insertAtTail(head, 99);
    print(head);
    cout << endl;
    insertInMiddle(head, 23, 2);
    insertInMiddle(head, 24, 3);
    insertInMiddle(head, 25, 4);
    print(head);
    cout << "\n\nDELETION BELOW\n\n";

    // now we will study how to delete a node in a linked list
    cout << endl;
    deleteFromHead(head);
    deleteFromHead(head);
    print(head);
    cout << endl;
    deleteTail(head);
    print(head);
    cout << endl;

    node* head1 = NULL;
    insertAtHead(head1, 54);
    cout << "|||\n\n";

    print(head1);
    cout << endl;
    deleteTail(head1);
    print(head1);
    cout << endl;

    //delete from middle
    print(head);
    cout << endl;
    deleteFromMiddle(head, 2);  //means delete 2nd node
    print(head);
    cout << endl;

    if (search(head, 2)) {
        cout << "element found\n";
    }
    else {
        cout << "element not found\n";
    }

    if (searchRecursive(head, 2)) {
        cout << "element found\n";
    }
    else {
        cout << "element not found\n";
    }
}