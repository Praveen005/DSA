//Here we will have a look on Deep and Shallow copy
#include<iostream>
#include<cstring>
using namespace std;
class car {

private:
	float price;

public:
	//declared a constant data type member
	const int msp; // Initialization here isn't allowed
	int model_no;

	char *name;
	car(): msp(65) {
		name = NULL;
	}
// constructor

	//this is initialization list
	car(float p, int model, char* n): price(p), msp(65) {

		model_no = model;

		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	void print() const {
		cout << "price: " << price << endl;
		cout << "model number: " << model_no << endl;
		cout << "name: " << name << endl;
		cout << "MSP " << msp << endl;
	}
	// Look at this copy constructor, you will notice that
	//the value of 'x' is not getting altered in following program
	// So better practice in such case is to use constant before data types
	//Taki galti se bhi galti na ho:)
	car( const car &x): msp(x.msp) {
		price = x.price;
		name = x.name;
		model_no = x.model_no;

		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	void operator=(const car &x) {
		price = x.price;
		model_no = x.model_no;
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}


	/*
	~car() {

	}
	*/


	~car() {
		cout << "Deleted " << name << endl;
		if (name != NULL) {
			delete[] name;
		}
	}
	//discount not getting changed so made it const
	// it actually makes debugging easier
	// This is also an non-constant function, It updates the value of price (data member)
	float apply_discount(const float discount) const {
		return price * (1 - discount);
	}

	// This function is not constant
	// because it changes/updates the value of Price data member
	void set_price( const float p) {   // This function is setter
		price = p;
	}

	//Those functions which don't update the data members of a class are constant function

	float get_price() const {    // This function is getter
		return price;
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

	// car d = c;
	// car d(c);
	car d;
	d = c;


	cout << "\nPrinting the info of car D:\n";
	d.print();
	d.name[0] = 'A';
	cout << "\n\n";

	// see the output, only name of car d has changed from BMW to AMW
	// This was deep copy;
	c.print();
	d.print();

	// Dynamically allocated object
	car* e = new car(10, 20, "ALTO");

	(*e).print();
	cout << "\n\n";
	cout << "\nPrinting for e: \n";
	e->print();
	//deleting Dynamically allocated object
	delete e;

}
