#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string s ;
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

	string s ;
	cin >> s;
	int n;
	cin >> n;
	string s1[n];
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = s.find(s1[i]);

			int y = s.find(s1[j]);

			if (x == y) {

				swap (s1[i], s1[j]);
			}
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {

			stringRemover(s, s1[i]);
		}
	}
	cout << s ;

}

/*

Input:
KUKUKAKIKUKAKEKKUKAKAKKUKAKUKAKU
2
KEK
UK

Output:
KAKIKAKAKAKKAKAKU

Input:
HEATHLEDGER
2
HEATH
LEDGER

Output:


Input:
KAPKAPPAPAK
1
KAPPA

Output:
K

Input:
CABAI
3
ABA
AB
B

Output:
CAI

AABCBC
2
BC
ABC

KULEK
2
KEK
UL


*/