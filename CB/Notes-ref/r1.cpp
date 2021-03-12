// vector continued
// vector basics : lecture two
#include<iostream>
#include<vector>
using namespace std;
#define ll long long


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>v {1, 2, 3, 4, 5};
	for (int x : v) {
		cout << x << ",";
	}
	cout << endl;
	v.push_back(6);
	for (int x : v) {
		cout << x << ",";
	}
	cout << endl;

	v.pop_back();
	for (int x : v) {
		cout << x << ",";
	}
	cout << endl;
	// v.insert(v.begin() + 2 , 200);
	// for (int x : v) {
	// 	cout << x << ",";
	// }
	// cout << endl;
	// v.insert(v.begin() + 2 , 4, 200);
	// for (int x : v) {
	// 	cout << x << ",";
	// }
	// cout << endl;
	v.erase(v.begin() + 2 , v.begin() + 4);
	for (int x : v) {
		cout << x << ",";
	}
	cout << endl;

}



// 1.  https://ideone.com/BeBrbQ
// 2.  https://ideone.com/lXj4OP
// 3.  https://ideone.com/Jc3OTf
// 4.  https://ideone.com/JoTKpW