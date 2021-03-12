#include<iostream>
#include<string>
using namespace std;
#define ll long long

ll numberExtracter(char * carr, ll m) {
	ll num = 0;
	ll factor = 1;
	for (ll i = m - 1; i >= 0; i--) {
		num += ((carr[i] - '0') * factor);
		factor *= 10;

	}
//	cout << num << endl;
	return num;
}
bool cBnumber(ll num , ll*div) {
	if (num == 0 || num == 1 ) {
		return false;
	}

	ll t = 9;
	while (t >= 0) {
		if (num == div[t]) {
			return true;
		}
		t--;
	}

	t = 9;
	while (t >= 0) {
		if (num % div[t] == 0) {
			return false;
		}
		t--;
	}
	return true;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	ll n;
	ll count = 0;
	cin >> n;
	char ch[n];
	for (ll i = 0; i < n; i++) {
		cin >> ch[i];
	}
	char s[n];
	ll finalNum;
	ll n1;
	ll div[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for (ll i = 0; i < n; i++) {
		for (ll j = i; j < n; j++) {
			ll m = 0;
			for (ll k = i; k <= j ; k++) {
				if (i <= n1) {
					continue;
				}
				s[m] = ch[k];
				m++;

			}
			ll num = numberExtracter(s, m);
			if (cBnumber(num, div) == true) {
				finalNum = num;
				n1 = j;
				//cout << finalNum << "  ";
				//cout << endl << "n1= " << n1 << endl;
				count++;
			}
		}
	}
	cout << count << endl;
}