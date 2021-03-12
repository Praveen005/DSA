//program to find most frequent character in a string
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pair<char , int> a[1009];
	string s;
	cin >> s;
	int count, count1 = 0;
//	sort(s.begin(), s.begin() + s.length());

	int n = s.length();
//	cout << "string length = " << s.length() << "  " << n << endl;;
	if (s.length() == 1) {
		cout << s;
		//	break;

	}
	for (int i = 0; i < n ; i++) {
		if (n == 1) {
			//	cout << s;
			break;

		}
		count = 1;
		for (int j = i; j < n; j++) {
			if (s[i] == s[j]) {
				a[count1].first = s[i];
				a[count1].second = count;
				count++;
			}

		}
		count1++;
	}




	// for (int i = 0; i < count1; i++) {
	// 	cout << a[i].first << "  " << a[i].second << endl;
	// }
	//cout << endl << endl;
	pair<char , int> ar[1009];
	ar[0].first = a[0].first;
	ar[0].second = a[0].second;
	int cnt = 1;
	for (int i = 1; i < count1; i++) {
		if (a[i].first == a[i - 1].first) {
			continue;
		}
		else {

			ar[cnt].first = a[i].first;
			ar[cnt].second = a[i].second;
			cnt++;
		}
	}
//	cout << "cnt =" << cnt << endl;
	if (s.length() == 1) {
		cout << s.length() << endl;
	}
	else {


		for (int i = 0; i < cnt; i++) {
			cout << ar[i].first << ar[i].second;
		}
	}

}