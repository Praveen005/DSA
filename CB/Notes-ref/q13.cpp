//problem : sot the string  ** revision
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string tokenFinder(string s , int key) {
	char* ptr = strtok((char*)s.c_str() , " " );
	while (key > 1) {
		ptr = strtok(NULL , " ");
		key--;
	}

	return (string) ptr;
}
int convertToInt(string a) {
	int sum = 0;
	int factor = 1;
	for (int i = a.length() - 1; i >= 0; i--) {
		sum = sum + ((a[i] - '0') * factor);
		factor *= 10;
	}
	return sum;
}
bool numericCompare(pair <string, string> s1 , pair <string, string> s2) {
	string key1 = s1.second;
	string key2 = s2.second;
	return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair <string, string> s1 , pair <string, string> s2) {
	string key1 = s1.second;
	string key2 = s2.second;
	return key1 < key2;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cin.get();
	string s[n];
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	int key;
	cin >> key;
	string reversal , ordering;
	cin >> reversal >> ordering;
	pair <string , string> strpair[100];
	for (int i = 0; i < n; i++) {
		strpair[i].first = s[i];
		strpair[i].second = tokenFinder(s[i] , key);
	}
	//now sorting should be done.
	if (ordering == "numeric") {
		sort(strpair , strpair + n, numericCompare);
	}
	else {
		sort(strpair , strpair + n, lexicoCompare);
	}

	if (reversal == "true") {
		for (int i = 0; i < n / 2; i++) {
			swap(strpair[i], strpair[n - i - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << strpair[i].first << endl;
	}
	return 0;
}