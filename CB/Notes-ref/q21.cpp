//program to find most frequent character in a string
#include<iostream>
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


	int n = s.length();
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
	int max = 0;
	char chh;
	for (int i = 0; i < count1; i++) {
		//	cout << a[i].second << " ";
		if (s.length() == 1) {
			//	cout << s;
			break;

		}

		if (max < a[i].second) {
			max = a[i].second;
			chh = a[i].first;
		}


	}
	if (s.length() != 1) {
		cout << chh << endl;
	}

}