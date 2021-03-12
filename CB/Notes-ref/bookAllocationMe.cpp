//book allocation problem
#include<iostream>
using namespace std;
bool validMinPage(int* pages , int n, int s , int mid) {
	int i;
	int k = 0;
	if (s > n) {
		return false;
	}

	for ( i = 1; i <= s; i++) {
		//n books are to be distributed to s students
		//koi aadmi nahi bachna chahiye aur koi book nahi bachna chahiye
		int sum = 0;
		while (sum <= mid  && k <= n) {
			sum += pages[k];
			k++;
		}
		k--;
	}

	i--;

	if (k == n && i == s) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n , st;
		cin >> n >> st;
		int pages[1000];
		int sum = 0;
		int ans = 0;
		//here the inputs are in ascending order i.e sorted
		for (int i = 0; i < n; i++) {
			cin >> pages[i];
			sum += pages[i];
		}
		int s = pages[n - 1];
		int e = sum;

		while (s <= e) {
			int mid = (s + e) / 2;

			bool ifValid = validMinPage( pages , n,  st , mid);
			if (ifValid) {

				ans = mid;
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		cout << ans << endl;
	}
}