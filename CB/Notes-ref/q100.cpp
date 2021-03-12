// vector basics : lecture one;
#include<iostream>
#include<vector>
using namespace std;
#define ll long long


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>v;
	for (int i = 0; i < 5; i++) {
		int no;
		cin >> no;
		v.push_back(no);
	}
	cout << endl;
//	cout << v.size() << "  " << v.capacity() << "  " << v.max_size() << endl;
	for (vector<int> :: iterator it = v.begin();  it != v.end(); it++) {
		cout << (*it) << "  ";
	}
	cout << endl;
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << v[i] << "  ";
	}

	vector<int>b(5, 2);
	cout << endl;
	for (int x : b) {
		cout << x << "  ";
	}

	//vector.clear()    clear every thing inside the vector completely

	b.clear();
	cout << endl;
	b = v;
	cout << endl;
	for (int x : b) {
		cout << x << " ";
	}
	cout << endl;

	vector<int> c;
	for (int i = 0; i < 6; i++) {
		int num;
		cin >> num;
		c.push_back(num);
	}
	for (int x : c) {
		cout << x << endl;
	}

}