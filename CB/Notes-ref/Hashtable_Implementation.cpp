#include<iostream>
using namespace std;
template<typename T>
class Node {
	//every Node that we store in the hash table, should have a string key, integer value and next pointer
public:
	string key;    //key: Burger , Value : 120 (its's price). don't mistake value with the one given by the hash function. HF gives index.
	int value;
	Node<T>* next;    // previously Node*  meant Node<int>*  :)  don't get confused

	//constructor
	Node(string key, T val) {
		// key = s; // This is correct if function argument is string s
		this->key = key; // when the argument is also key, then 'this->key' means key of the Node class
		value = val;
		next = NULL;
	}

	//Destructor
	//This is a recursive call.
	/*
		when you run delete next, it will call the destructor and so on...
		It initiates a destruction chain until next points to a NULL
	*/
	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

//yahan bhi template<typename T> likhna hoga, kewal upar likh dene se nahi hota, saare class ke upar likhna
// hota hai
template<typename T>
class HashTable {
private:
	Node<T>** table;    //pointer to an array of pointers
	int current_size;  // no. of Nodes in the linked list at any particular index;
	int TableSize;


	//don't want anyone from outsize to acces my Hash Function, that's why included it in the private method.
	int HashFunction(string key) {
		int index = 0;
		int p = 1;
		for (int i = 0; i < key.length(); i++) {
			index = index + (key[i] * p) % TableSize;
			index = (index % TableSize);
			p = (p * 27) % TableSize;			//instead of 27 u can choose any prime greater than 26
		}
		return index;
	}

	void ReHash() {
		Node<T>** oldTable = table;
		int oldTableSize = TableSize;
		// TableSize = (2 * TableSize) + 1;
		TableSize = (2 * TableSize);

		//Making table point to a new hashtable of new size
		table = new Node<T>*[TableSize];

		//Making every bucket of the New hash table point to NULL
		for (int i = 0; i < TableSize; i++) {
			table[i] = NULL;
		}
		//now that we have made a new hash table of increased size, but we are yet to
		//push a node at any index in the new hashtable, so the current_size=0;
		current_size = 0;
		//now inserting the key and value again in the new hashtable
		for (int i = 0; i < oldTableSize; i++) {
			Node<T>* temp = oldTable[i];
			while (temp != NULL) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
		}

		//now will delete the old hash table
		// deleting the linked list first
		for (int i = 0; i < oldTableSize; i++) {
			Node<T>* temp = oldTable[i];
			if (temp != NULL) {
				delete temp;
			}

		}
		//delete the table array now
		delete [] oldTable;
	}
public:
	//constructor
	HashTable(int ts = 7) {  // keep table size a prime number
		current_size = 0;
		TableSize = ts;
		table = new Node<T>*[TableSize];
		for (int i = 0; i < TableSize; i++) {
			table[i] = NULL;
		}
	}


	void insert(string key, int value) {
		int index = HashFunction(key);

		Node<T>* n = new Node<T>(key, value); //crated a new Node of type T

		//'ll insert the Nodes at head, you can insert it the tail as well
		n->next = table[index]; //currently table[index] has value NULL, so, n->next=NULL ho raha yahan
		table[index] = n;  //ab table[index] jo hai wo head ko point kar raha.
		current_size++;

		float LoadFactor = current_size / (1.0 * TableSize);
		// cout << "Cur_size-->" << current_size << " " << "TableSize-->" << TableSize << " " << "LF-->" << LoadFactor << endl;
		//I am taking threshold load factor=0.7
		if (LoadFactor > 0.7) {
			// cout << "Rehashing\n";
			ReHash();
		}
	}

	// not the part of the hash table class, we just want to look inside the hash table
	void print() {
		for (int i = 0; i < TableSize; i++) {
			cout << "Bucket " << i << " -> ";
			Node<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp->key << " -> ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key) {
		int index = HashFunction(key);

		/*
		following if() is not needed because  the index will will never exceed the tablesize
		kyun ki hamne table size se mod le rakha hai :) hahaha, Gadha :)

		if (index >= TableSize) {
			cout << "-->" << index << endl;
			return NULL;
		}
		*/


		//store the address of the bucket in a temporary variable
		Node<T>* temp = table[index];

		//now we will search for the node in the linked list associated with this bucket
		while (temp != NULL) {
			if (temp->key == key) {
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}


	void erase(string key) {
		int index = HashFunction(key);

		//store the address of the bucket in a temporary variable
		Node<T>* temp = table[index];
		if (temp == NULL) {
			return;
		}
		if (temp->key == key) {
			table[index] = temp->next;
			delete temp;
			return;
		}

		//now we will search for the node in the linked list associated with this bucket
		while (temp != NULL and temp->next != NULL) {
			if (temp->next->key == key) {
				temp->next = temp->next->next;
				delete temp->next;
				return;
			}
			temp = temp->next;
		}
		return;

	}

	T& operator[](string key) {
		//search for this key, in the hash table and see if it is pesent or not
		T* value_address = search(key);
		//if not present
		if (value_address == NULL) {
			T garbage ;
			insert(key, garbage);
			T* value_address = search(key);
		}
		return *value_address;
	}

};


int main() {
    //Implementation of Hashing
	HashTable<int> price_menu;
	price_menu.insert("Burger" , 121);
	price_menu.insert("Pepsi" , 122);
	price_menu.insert("BurgerPizza" , 123);
	price_menu.insert("Noodles" , 124);
	price_menu.insert("Coke" , 125);
	price_menu.insert("Fanta" , 105);
	price_menu.insert("Tuborg" , 325);
	price_menu.insert("dfgdfgf" , 35);
	price_menu.print();

	int* result = price_menu.search("Coke");
	if (result == NULL) {
		cout << "key not found!\n";
	}
	else {
		cout << *result << endl;
	}
	price_menu.erase("Coke");
	cout << "\n";
	price_menu.print();

	price_menu["Burger"] = 90;
	price_menu["Burger"] += 6;
	cout << "New price of Burger: " << price_menu["Burger"] << endl;
}

/*
output:

Bucket 0 -> 
Bucket 1 -> 
Bucket 2 -> Noodles -> 
Bucket 3 -> Burger -> 
Bucket 4 -> dfgdfgf -> Coke -> 
Bucket 5 -> BurgerPizza -> 
Bucket 6 -> 
Bucket 7 -> Tuborg -> 
Bucket 8 -> Fanta -> 
Bucket 9 -> 
Bucket 10 -> 
Bucket 11 -> Pepsi -> 
Bucket 12 -> 
Bucket 13 -> 
125

Bucket 0 -> 
Bucket 1 -> 
Bucket 2 -> Noodles -> 
Bucket 3 -> Burger -> 
Bucket 4 -> dfgdfgf -> 
Bucket 5 -> BurgerPizza -> 
Bucket 6 -> 
Bucket 7 -> Tuborg -> 
Bucket 8 -> Fanta -> 
Bucket 9 -> 
Bucket 10 -> 
Bucket 11 -> Pepsi -> 
Bucket 12 -> 
Bucket 13 -> 
New price of Burger: 96	


*/





