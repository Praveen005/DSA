

#include<iostream>
#include<algorithm>

using namespace std;
bool compare(pair<int, int>s1 , pair<int, int>s2) {
	int a = s1.second;
	int b = s2.second;
	return a < b;
}


int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cin >> b[i];
		}
		sort(a, a + n);
		int start = a[0];
		int end = b[0];
		int count = 1;
		for (int i = 1; i < n; i++) {
			auto lb = lower_bound(a, a + n, end) - a;
			if (a[lb] >= end) {
				start = a[lb];
				end = b[lb];
				count++;
			}
		}
		cout << count << endl;
	}


}
// for (int i = 0; i < n; i++) {
// 	cout << a[i] << " ";
// }