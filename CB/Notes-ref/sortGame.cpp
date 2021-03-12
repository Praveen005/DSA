#include <iostream>
#include<algorithm>
using namespace std;
bool compare(pair<string , int > sintPair1 , pair<string , int > sintPair2) {
	int n1 = sintPair1.second;
	int n2 = sintPair2.second;
	if (n1 == n2) {
		return sintPair1.first < sintPair2.first;
	}
	return n1 > n2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int cutoff;
	cin >> cutoff;
	int n;
	cin >> n;
	pair<string , int > sintPair[100006];
	for (int i = 0; i < n; i++) {
		cin >> sintPair[i].first;
		cin >> sintPair[i].second;
		// string s;
		// getline(cin, s, ' ');
		// int n1;
		// cin >> n1;
		// sintPair[i] = make_pair(s, n1);
	}
	sort(sintPair, sintPair + n, compare);
	for (int i = 0; i < n; i++) {
		if (sintPair[i].second >= cutoff)
			cout << sintPair[i].first << " " << sintPair[i].second << endl;
	}

	// string s[1];
	// cin >> s[0];
	// cout << s[0] << endl;
}
