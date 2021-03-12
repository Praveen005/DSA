#include<iostream>
#include<cstring>
using namespace std;
class car {
private:
	float price;

public:
	int model_no;
	char name[20];
	void print() {
		cout << "price: " << price << endl;
		cout << "model number: " << model_no << endl;
		cout << "name: " << name << endl;
	}
	void set_price(float p) {   // This function is setter
		price = p;
	}

	float get_price() {    // This function is getter
		return price;
	}

	// we initialized all the data members in this constructor
	// I created 3 constructors of same name: this is called constructor overloading
	car(float p, int model, char* n) {
		cout << "Inside the constructor: " << endl;

		price = p;
		model_no = model;

		strcpy(name, n);
	}

	// we created this constructor if we only wanted to initialize the price of the car
	car(float p) {
		price = p;
	}

	car() {
		cout << "\nBHAI mai constructor ke andar khada hun: " << endl;
	}

	// making my very own copy constructor
	// Passed argument as reference
	car( car &x) {
		price = x.price;
		model_no = x.model_no;
		strcpy(name, x.name);
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//we are reading about constructor

	car c(100, 11, "AUDI");  // Parameterised constructor
	c.print();

	car d(c);	// copy constructor
	// default copy constructors produces shallow copy
	// for shallow and deep copy constructor refer r78.cpp
	cout << "\nPrinting dtails of car D:\n";

	d.print();
	d.set_price(1234);
	d.print();
	int p = c.get_price();
	cout << p << endl;

	// another way of copying the object
	car f = c;
	f.print();


}


// constructor done
// now copy constructor