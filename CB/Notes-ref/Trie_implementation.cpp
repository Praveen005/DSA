#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;

//let's make a custom data type 'Node'
class Node {
public:
	//every Node will have a variable to store data, a hashhmap and a boolean value
	//it will hold data
	char data;
	//store the mapping of char with the Node*
	unordered_map<char, Node*> children;
	//To denote of the Node is terminal or not
	bool terminal;

	//constructor
	Node(char d) {
		data = d;
		terminal = false;
	}
};


class Trie {
private:
	// 1 data member, only the root node
	//initialized with a NULL/garbage character
	Node* root;
	//count denotes the number of words we have inserted in the Trie
	int count;

public:
	//constructor
	Trie() {
		//root is going to point to a new node whode data is NULL
		root = new Node('\0');
		count = 0;
	}

	//insert a word into the Trie
	/*
		we will start traversing the tree from the root
		and then iterate over all the characters of the given word.

		let's insert "NO". we'll ask root if 'N' is there,
		if it says not present, then make a new node having character 'N'
		if yes then move to the Node with 'N' and ask it if it maps to 'O' and so on..
	*/
	void insert(char* w) {
		Node* temp = root;
		for (int i = 0; i < w[i] != '\0'; i++) {
			char ch = w[i];
			/*
				access the children map of the temp node and check if the count of character ch is 0 or 1 in that hash map,
				0: not present & 1: present
				if present go to the node whose data is character ch.
				if not present then form a new node and map the ch with the new node.
			*/
			if (temp->children.count(ch)) {
				temp = temp->children[ch];
			}
			else {
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}

		}
		//now we are at the last node after exiting the for() loop
		temp->terminal = true;

	}

	bool find(char* w) {
		Node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			//if the character is not present means the word is not present
			if (temp->children.count(ch) == 0) {
				return false;
			}
			//if present then move to the Node whose data is ch
			else {
				temp = temp->children[ch];
			}
		}
		//Now that we've exited the for() loop, means temp is at the last character. if it is the terminal node, return true, else false.
		return temp->terminal;
	}
};



int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Trie t;
	char words[][10] = {"a", "hello", "not", "news", "apple"};
	char w[10];
	cin >> w;
	for (int i = 0; i < 5; i++) {
		t.insert(words[i]);
	}

	if (t.find(w)) {
		cout << "Word is present\n";
	}
	else {
		cout << "Word is not present\n";
	}

	/*
		if you search for "no", the result will be false, bcz we have inserted "not".
		
		hamne "no" insert nahi kiya hai.
	*/

}

/*
input:
apple

output:
Word is present

*/
