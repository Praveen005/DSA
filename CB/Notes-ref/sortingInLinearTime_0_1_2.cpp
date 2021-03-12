#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0 , h = n - 1, mid = l;
	//mudda ye hai bhai ki
	// 0's mile to use l ke sath swap karke left side lana hai,
	// agar mid ko 2 mile to h ke sath swap karke use right side pahunchana hai.
	//1 mile to chood do.  kyun?
	// wo iss liye kyun ki 0 aur 2 agar apne apne jagah pahunch gaye to
	// 1 khud hi apne jagah pe milega aapko :)
	// l just means left pointer
	//h is right pointer
	//apun ko bas digits ko sahi jagah pahuchana hai.
	// m ka use array traverse karne me use aayega.

	while (mid <= h) {
		if (a[mid] == 0) {
			swap(a[l] , a[mid] );
			l++; mid++;
		}
		else if (a[mid] == 1) {
			mid++;
		}
		else {
			swap(a[h], a[mid]);
			h--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}