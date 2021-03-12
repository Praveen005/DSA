
#include<iostream>
using namespace std;
// void mF(string s) {

// 	int n = s.length();
// 	char ch;

// 	ch = s[0];

// 	char ch1;
// 	int max = 0;
// 	int count = 1;
// 	for (int i = 1; i < n; i++) {
// 		if (s[i] == s[i - 1]) {
// 			count++;
// 		}
// 		else if (s[i] != s[i - 1]) {

// 			if (max < count) {
// 				max = count;
// 				ch1 = ch;
// 			}
// 			ch = s[i];

// 			count = 1;

// 		}

// 	}
// 	cout << max << endl;
// }

// void replace(string* s, int key) {


// }

// void compression(string s) {



// 	int n = s.length();
// 	char ch;

// 	ch = s[0];
// 	cout << ch;
// 	int count = 1;
// 	for (int i = 1; i < n; i++) {
// 		if (s[i] == s[i - 1]) {
// 			count++;
// 		}
// 		else if (s[i] != s[i - 1]) {
// 			cout << count;
// 			ch = s[i];
// 			cout << ch;
// 			count = 1;

// 		}

// 	}
// 	cout << count;
// }














int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int key; cin >> key;
	string s;
	cin >> s;
	string s1;
	int cnt1 = 0;
//	mF(s);
	//string s2[100];
	int n = s.length();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				if (j - i + 1 < key) {
					continue;
				}
				s1[cnt1] = s[k];

				//	cout << s[k] << " ";
			}
			cout << s1[0] << endl;

			//	s2[cnt1] = s1;
			//	cnt1++;
			if (j - i + 1 < key) {
				continue;
			}
			//	cout << endl;
			//	compression(s1);
		}
	}

}