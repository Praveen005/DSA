//prata problem
//min time taken too cook that paratha
//mim-max ka problem hai so we'll try to look for monotonic search space

#include<iostream>
using namespace std;
bool parathaTimeChecker(int *rank , int mid, int chefCount , int n) {

	int roti = 0;
	for (int i = 0; i < chefCount; i++) {
		int fac = 1;
		int sum = 0;

		while (sum <= mid ) {

			sum += (fac * rank[i]);

			fac++;
		}

		roti += (fac - 2);

	}

	if (roti >= n) {

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
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int chefCount;
		cin >> chefCount;
		int rank[chefCount];
		for (int i = 0; i < chefCount; i++) {
			cin >> rank[i];
		}
		int ans = 0;
		int s = 0;
		int e = 50000000;
		while (s <= e) {

			int mid = (s + e) / 2;

			bool check = parathaTimeChecker(rank , mid, chefCount , n);
			if (check) {
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
