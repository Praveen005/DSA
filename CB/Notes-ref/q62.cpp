#include<iostream>
using namespace std;
bool validMin(int* pages , int b, int s, int mid) {
//	cout << "b " << b << ", s " << s << ", mid " << mid << endl;
//	int count = 0;
	int student_count = 1;
	int pages_read = 0;
	for (int i = 0; i < b; i++) {
		//count++;
		//	cout << count << endl;
		if (pages_read + pages[i] > mid) {
			//then we will need new student
			student_count++;
			pages_read = pages[i];
			if (student_count > s) {
				return false;
			}
		}
		else {
			pages_read += pages[i];
		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int s, b;
		cin >> b >> s;
		int pages[b];
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < b; i++) {
			cin >> pages[i];
			sum += pages[i];
		}
		//cout << sum << endl;
		int st = pages[b - 1];
		//cout << st << endl;
		int e = sum;
		while (st <= e) {
			int mid = (st + e) / 2;
			//cout << mid << endl;
			bool check = validMin( pages , b,  s,  mid);
			if (check) {

				ans = mid;
				//		cout << ans << endl;
				e = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
		cout << ans << endl;
	}
}