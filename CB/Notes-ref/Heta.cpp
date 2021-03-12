#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string s ;
//cin >> s;
int gettingIndex(string a , string s) {
	return s.find(a);

}
bool compare(string a, string b) {

	int x = gettingIndex(a, s);

	int y = gettingIndex(b , s);
	if (x == y) {
		return a.length() < b.length();
	}

	return x < y;
}


string stringRemover(string &s, string sample) {
	int index = s.find(sample);

	while (index >= 0) {
		int len = sample.length();
		s.erase(index, len);

		index = s.find(sample);
	}
	return s;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// string s ;
	cin >> s;
	int n;
	cin >> n;
	string s1[n];
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}

	sort(s1, s1 + n, compare);

	for (int i = 0; i < n; i++) {

		stringRemover(s, s1[i]);
	}
	cout << s ;

}