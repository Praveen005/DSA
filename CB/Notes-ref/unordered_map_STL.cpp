#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{


	unordered_map<string, int> m;

	//1. Insert
	m.insert(make_pair("Banana", 12));

	//aliter
	pair<string, int>p;
	p.first = "Guava";
	p.second = 23;
	m.insert(p);

	//aliter
	m["Pinapple"] = 34;


	//2. search
	//find function

	string fruit;
	cin >> fruit;

	unordered_map<string, int>::iterator it = m.find(fruit);
	if (it != m.end()) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not present\n";
	}
	//erase
	m.erase(fruit);

	//another way to search is using the count() function
	//Map stores only the unique keys
	//i.e. if you do m["Banana"]=78; the value will get updated and not a new Banana will get added
	//function will return only 0 or 1, cz fruit is either present or not present cz it is unique.
	if (m.count(fruit)) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not present.\n";

	}
	//updarting the valuer
	m["Banana"] += 10;
	cout << m["Banana"] << endl;

	m["Lichi"] = 54;
	m["Plum"] = 12;
	m["Cucumber"] = 31;

	//Iterating over all the key- value pairs
	// (*it) will give you  the pair, now you can get pair.first and pair.second
	//the result is lexiographically sorted
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}


	cout << endl;
	// for each loop
	for (auto p : m) {
		cout << p.first << " " << p.second << endl;
	}

}

/*
input:
Pinapple



output:
Price of Pinapple is 34
Fruit is not present.
22
Cucumber 31
Banana 22
Plum 12
Lichi 54
Guava 23

Cucumber 31
Banana 22
Plum 12
Lichi 54
Guava 23

*/


