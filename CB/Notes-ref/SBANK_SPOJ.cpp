#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;
bool compare(string s1, string s2) {
	return s1 < s2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cin.get();
		string s[100005];
		for (int i = 0; i < n; i++) {
			getline(cin, s[i]);
		}
		sort(s, s + n, compare);


		int count1 = 1, count2 = 0;
		pair<string, int>strpair[100005];
		strpair[count2] = make_pair(s[0], count1);
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				strpair[count2].second++;
			}
			else {
				count2++;
				count1 = 1;
				strpair[count2] = make_pair(s[i], count1);
			}
		}
		for (int i = 0; i <= count2; i++) {
			cout << strpair[i].first << " " << strpair[i].second << endl;
		}
		if (t != 0)
			cout << endl;
	}


}

/*
03 10103538 2222 1233 6160 0141 1
03 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0141 2
30 10103538 2222 1233 6160 0142 2

30 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0143 1
30 10103538 2222 1233 6160 0144 1
30 10103538 2222 1233 6160 0145 1
30 10103538 2222 1233 6160 0146 1
*/

