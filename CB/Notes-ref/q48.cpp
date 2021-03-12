

#include<iostream>
#include<algorithm>

using namespace std;
bool compare(pair<int, int>s1 , pair<int, int>s2) {
	int a = s1.second;
	int b = s2.second;
	return a < b;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	int maxm = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		pair<int , int> arr[10009];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
			cin >> arr[i].second;
		}
		sort(arr, arr + n , compare);
		for (int i = 0; i < n; i++) {
			cout << arr[i].first << " ";
			cout << arr[i].second << endl;
			//cout << abs(arr[i].first - arr[i].second) << endl;
		}

		for (int j = 0; j < n; j++) {


			int start = arr[j].first;
			int end = arr[j].second;
			int count = 1;
			for (int i = 0; i < n; i++) {
				if (i == j) {
					continue;
				}
				if (arr[i].first >= end) {
					start = arr[i].first;
					end = arr[i].second;
					count++;
				}

			}
			//	cout << "count : " << count << endl;
			maxm = max(maxm , count);
		}
		cout << maxm << endl;
	}
}

