#include<iostream>
#include<algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	//make_pair(a, b);
	cin >> a >> b;
	pair<int, int>p ; make_pair(a, b);
	p = make_pair(a, b);
	cout << p.first << " " << p.second << endl << endl;

	int arr[] = {1, 2, 3};
	cout << 1 << " " << 2 << " " << 3 << endl;
	for (int i = 0; i < 8; i++) {
		next_permutation(arr, arr + 3);
		for (int j = 0; j < 3; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
	}
}