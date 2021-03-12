//aggresive cows

#include<iostream>
#include<algorithm>
using namespace std;
bool validPlacing(int stalls[]  , int min_sep, int cows , int n) {
	int last_placing = stalls[0];
	int count = 1;

	for (int i = 1; i < n; i++) {
		if (stalls[i] - last_placing >= min_sep) {

			last_placing = stalls[i];
			count++;
		}
		//count++;
		if (count == cows) {
			return true;
		}
	}
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	int ans = 0;
	while (t--) {
		int n , cows;
		cin >> n >> cows;
		int stalls[n];
		for (int i = 0; i < n; i++) {
			cin >> stalls[i];
		}
		sort(stalls, stalls + n);
		int s = stalls[0];
		int e = stalls[n - 1] - stalls[0];
		while (s <= e) {
			int mid = (s + e) / 2;
			//	int min_step=mid
			bool cowRakhPaaye = validPlacing(stalls, mid, cows, n);
			if (cowRakhPaaye) {
				ans = mid;
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}




