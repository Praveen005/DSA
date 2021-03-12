// vector 1st and 2nd lectures
#include<iostream>
#include<vector>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>a(5, 10);
	for (int x : a) {
		cout << x << " ";
	}
	cout << sizeof(a) << endl;

	vector<int> v(a.begin(), a.end());
	for (int x : v) {
		cout << x << " ";
	}

	cout << endl << v.capacity() << endl;
	cout << v.size() << endl;
	cout << v.max_size() << endl;
	v.clear();
	cout << v.size() << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		v.push_back(no);
	}

	for (int x : v) {
		cout << x << " ";
	}
	v.pop_back();
	cout << endl;
	for (int x : v) {
		cout << x << " ";
	}

	v.insert(v.begin() + 2 , 2, 7);
	cout << endl;
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	v.erase(v.begin() + 2, v.begin() + 5);
	for (int x : v) {
		cout << x << " ";

	}
	cout << endl;
	cout << endl;
	cout << v.size() << endl;
	v.resize(6, 99);
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	cout << endl << v.size() << "  " << v.capacity() << endl;
	//size gives the total no of elements present in the array;
	if (v.empty()) {
		cout << " yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

}