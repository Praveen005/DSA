/*
s: a string representation of an integer
	n: an integer that represents the length of the integer string
k: an integer that represents the maximum number of changes allowed

Sample Input 0
4 1
3943
Sample Output 0
3993

Sample Input 1
6 3
092282
Sample Output 1
992299


Sample Input 2
4 1
0011
Sample Output 2
-1

*/
#include<iostream>
#include<cstring>
using namespace std;
#define e (n-1-i)
const int N = 100005;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;  cin >> n >> k;
	char s[N];
	int ind[N];
	cin >> s;
	int cnt = 0;

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[e]) {
			ind[i] = 1;
			s[i] = s[e] = max(s[i], s[e]);
			cnt++;
		}
	}
	if (cnt > k) {
		cout << -1 << endl;
	}
	else {
		cnt = 0;
		for (int i = 0; i < n / 2; i++) {
			if (cnt >= k) {
				break;
			}
			if (ind[i] == 1  && s[i] == '9') {
				cnt++;
				//cout << i << " ";
			}
			if (s[i] != '9' && (k - cnt) >= 2) {
				s[i] = s[e] = '9';
				cnt += 2;
			}

		}
		if (n % 2 == 1 && cnt < k) {
			s[n / 2] = '9';
		}
		cout << s << endl;
		//cout << strlen(s) << endl;
	}

}