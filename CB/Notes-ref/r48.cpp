#include<iostream>
#include<cstring>
using namespace std;
bool all9s(char *ch , int n) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		if (ch[l] != '9' || ch[r] != '9') {
			return false;
		}
		l++;
		r--;
	}
	return true;
}
void palin(char* ch, int n) {
	bool leftsmaller = false;
	int l, r;
	int mid = n / 2;
	r = (n % 2) ? mid + 1 : mid;
	l = mid - 1;
	//
	while (l >= 0 && ch[l] == ch[r]) {
		l--;
		r++;
	}
	//
	if (ch[l] < ch[r] || l < 0) {
		leftsmaller = true;
	}
	while (l >= 0) {
		ch[r] = ch[l];
		l--;
		r++;
	}
	//

	if (leftsmaller) {
		// r=(n%2)?mid+1:mid;
		l = (n % 2) ? mid : mid - 1;
		int carry = 0;
		char c = ch[l];
		ch[l] = ((((ch[l] - '0') + 1) % 10) + 48);
		if (c == '9') {
			carry = 1;
		}
		else {
			carry = 0;
		}
		l--;
		// cout << l << "		";
		while (l >= 0) {
			// cout << l << endl;
			c = ch[l];
			//cout<<"carry: "<<carry<<endl;
			// cout<<"c: "<<c<<endl;
			ch[l] = ((((ch[l] - '0') + carry) % 10) + 48);
			//cout<<"ch[l]"
			if (c == '9') {
				carry = 1;
			}
			else {
				carry = 0;
			}
			l--;
		}
		l = mid - 1;
		r = (n % 2) ? mid + 1 : mid;
		while (l >= 0) {
			ch[r] = ch[l];
			l--;
			r++;
		}
	}


}
void palingenerator(char* ch) {
	int n = strlen(ch);
	if (all9s(ch, n)) {
		cout << 1;
		for (int i = 1; i < n; i++) {
			cout << 0;
		}
		cout << 1 << endl;
	}
	else {
		palin(ch, n);
		cout << ch << endl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	char ch[1000009];
	while (t--) {
		cin >> ch;
		palingenerator(ch);
	}
}