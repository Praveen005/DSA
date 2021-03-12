#include<iostream>
#include<vector>
using namespace std;
void func(vector<int>&vect) {
	vect.push_back(30);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//1. form the prime sieve

	int a[1000] = {0};
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	// func(a);
	// cout << a[3];

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	func(v);
	cout << v.size() << endl;
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;


}

