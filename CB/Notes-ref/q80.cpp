// getting max length bitonic subarray
#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
bool bitonic(int *a , int n) {
	int l = 0;
	int r = n - 1;
	int count1 = 0;
	int count2 = 0;
	while (a[l] < a[l + 1] || l < n) {
		if (a[l] <= a[l + 1]) {
			count1++;
			l++;
		}
		else {
			break;
		}
	}
	//now left index is fixed
	for (int i = n - 1; i >= l; i--) {
		if (a[i - 1] >= a[i]) {
			count2++;
		}
		else {
			break;
		}
	}
	if ((count2 + count1 + 1) == n) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);

	freopen("output.txt" , "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	int len = 1;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n - i; j++) {
			string sub = s.substr(j, len);
		}
		len++;
	}



}