//Here we will have a look on Deep and Shallow copy
#include<iostream>
#include<cstring>
using namespace std;
class car {
private:
	float price;

public:
	const int msp = 99;
	int model_no;

	char *name;
	car() {
		name = NULL;
	}

	car(float p, int model, char* n) {
		price = p;
		model_no = model;

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
		name = x.name;
		model_no = x.model_no;
		// we allocated a new memory to the new array
		// This is deep copy
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	void operator=(car &x) {
		price = x.price;
		model_no = x.model_no;
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	// default destructor looks like
	/*
	~car() {

	}
	*/

	// since data member 'name' is dynamically allocated
	~car() {
		cout << "Deleted " << name << endl;
		if (name != NULL) {
			delete[] name;
		}
	}


};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	car c(100, 112, "BMW");
	cout << c.msp << endl;
	cout << "Printing the info of car c:\n";
	c.print();


	car d;
	d = c;


	cout << "\nPrinting the info of car D:\n";
	d.print();
	d.name[0] = 'A';
	cout << "\n\n";

	c.print();
	d.print();

	// Dynamically allocated object
	car* e = new car(10, 20, "ALTO");

	(*e).print();
	cout << "\n\n";
	e->print();
	//deleting Dynamically allocated object
	delete e;

}
