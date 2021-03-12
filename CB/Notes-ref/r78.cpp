//Here we will have a look on Deep and Shallow copy
#include<iostream>
#include<cstring>
using namespace std;
class car {
private:
	float price;

public:
	int model_no;
	// previously it was ( char name[20] ) : statically allocated
	char *name;   // It is just a pointer, later we will allocate memory to it dynamically
	car() {
		name = NULL;
	}
// constructor
	car(float p, int model, char* n) {
		price = p;
		model_no = model;
		// upar kewal ek pointer hai
		// to initialize it with a name, we need to allocate some memory first.
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	void print() {
		cout << "price: " << price << endl;
		cout << "model number: " << model_no << endl;
		cout << "name: " << name << endl;
	}
	// copy constructor: Deep copy
	car(car &x) {
		price = x.price;

		model_no = x.model_no;
		// we allocated a new memory to the new array
		// This is deep copy
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}


};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	car c(100, 112, "BMW");
	cout << "Printing the info of car c:\n";
	c.print();

	// car d = c;
	car d(c);
	cout << "\nPrinting the info of car D:\n";
	d.print();
	d.name[0] = 'A';
	cout << "\n\n";

	// see the output, only name of car d has changed from BMW to AMW
	// This was deep copy;
	c.print();
	d.print();




}
