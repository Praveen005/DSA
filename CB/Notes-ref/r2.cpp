#include<iostream>
#include<vector>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif

	vector<int>a(5, 2);

	for (int i = 0; i < 5; i++) {
		int no;
		cin >> no;
		a.push_back(no);

	}

	cout << endl;
	a.pop_back();
	vector < int > v(a.begin(), a.end());
	cout << endl;

	for (int y : v) {
		cout << y << " ";
	}
	cout << endl;
	v.insert(v.begin() + 3 ,  v.begin() + 5, 100);
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;




}