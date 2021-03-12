#include<iostream>
// we don't use angular bracket '< >' when we include user defined header file 'vector.h'
#include"vector2.h"
using namespace std;

int main() {

	// did you find sth weird below?
	// it should have been vector<int>v  and not vector v;
	// for that you need to define a template
	// refer to :

	/*
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	*/
	vector<char> v;
	v.push_back(71);
	v.push_back(72);
	v.push_back(73);
	v.push_back(74);
	v.push_back(75);

	for (int i = 0; i <= 3; i++) {
		char ch = v[i];
		cout << ch << " ";
	}
	cout << "\nsize: " << v.size() << endl;
	cout << "capacity: " << v.capacity() << endl;


	v.pop_back();
	cout << "\nsize: " << v.size() << endl;
	cout << "capacity: " << v.capacity() << endl;
	cout << "front element : " << v.front() << endl;
	cout << "last element: " << v.back() << endl;

}