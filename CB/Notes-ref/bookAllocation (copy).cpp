// //Book allocation problem from HackerBlocks
// // used Binary search here
// #include<iostream>
// using namespace std;
// bool validMin(int* pages , int b, int s, int mid) {

// 	int student_count = 1;
// 	int pages_read = 0;
// 	for (int i = 0; i < b; i++) {

// 		if (pages_read + pages[i] > mid) {
// 			//now we will need new student
// 			student_count++;
// 			pages_read = pages[i];
// 			if (student_count > s) {
// 				return false;
// 			}
// 		}
// 		else {
// 			pages_read += pages[i];
// 		}

// 	}
// 	return true;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int s, b;
// 		cin >> b >> s;
// 		int pages[b];
// 		int sum = 0;
// 		int ans = 0;
// 		for (int i = 0; i < b; i++) {
// 			cin >> pages[i];
// 			sum += pages[i];
// 		}
// 		// st here means starting index of the space over which we'll apply Binary Search
// 		//e - end
// 		int st = pages[b - 1];
// 		int e = sum;

// 		while (st <= e) {
// 			int mid = (st + e) / 2;

// 			bool check = validMin( pages , b,  s,  mid);
// 			if (check) {

// 				ans = mid;

// 				e = mid - 1;
// 			}
// 			else {
// 				st = mid + 1;
// 			}
// 		}
// 		cout << ans << endl;
// 	}
// }


#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long
bool flag = false;
bool check(ll a[], ll n, ll m, ll mid) {
	ll sum = 0;
	ll count = 1;
	for (ll i = 0; i < n; i++) {
		if (sum + a[i] > mid) {

			count++;
			sum = a[i];
			if (count > m) {
				return false;
			}
		}
		else {
			sum += a[i];
		}
	}
	return true;
}
void mmpage(ll a[], ll n, ll s, ll e, ll m) {
	ll ans = -1;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (check(a, n, m, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	cout << ans << endl;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	ll t; cin >> t;
	while (t--) {
		ll s = 0, e = 0;
		ll n; cin >> n;
		ll a[1000006];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			e += a[i];
		}

		ll m; cin >> m;
		mmpage(a, n, s, e, m);
	}
	return 0;
}