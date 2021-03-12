#include<iostream>
#include<list>
#include<vector>
using namespace std;

// template me class ka koi bhi naam ho sakta hai
// eg. class compare ke jagah, class ramu bhi likh sakte ho
template<class ForwardIterator, class T, class compare >
ForwardIterator search(ForwardIterator start, ForwardIterator end , T key, compare cm) {
	while (start != end) {
		if (cm(key , *start)) {
			return start;
		}
		start++;
	}
	return end;
}



class book {

public:

	string name;
	int price;
	//Default constructor
	book() {
	}
	//Parametrised constructor
	book(string s , int n) {
		this-> name = s;
		this->price = n;
	}

};


// Making a comparator class
// why?
// bcz: we exactly are not aware of as to what should i compare,
// compare the name? or the price?

class bookcompare {
public:
	// here suppose we make an object, bookcompare cmp
	// it will take two inputs,   compare(book A, book B) : don't you think it looks like a function?
	// it it actually called a functional object ot Functor
	bool operator()(book &A, book &B) {
		if (A.name == B.name) {
			return true;
		}
		return false;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	book b1("c++", 100);       // Old edition
	book b2("python", 110);
	book b3("java", 123);
	book b4("kotlin", 125);


	// storing books in a list
	// you can store them in a vector as well
	// vector<book>l;
	list<book>l;
	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);
	l.push_back(b4);

	book bookToFind("c++", 165);  //latest edition

	// made a comparator object, 'cmp'
	// we will pass this comparator object to the template function in the same way
	//as we used  to pass in sort() function, sort(a,a+n,compare);
	bookcompare cmp;

	list<book>::iterator it = search(l.begin(), l.end(), bookToFind, cmp);
	// vector<book>::iterator it = search(l.begin(), l.end(), bookToFind, cmp);

	// or
	// auto it = search(l.begin(), l.end(), bookToFind, cmp);

	if (it != l.end()) {
		cout << "Book found";
	}
	else {
		cout << "Book not found";
	}



}