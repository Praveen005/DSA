// // problem : https://codezen.codingninjas.com/practice/10336/2149/toggle-k-bits
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n;
// 	cin >> n;
// 	int a[1000];
// 	int b[1000];
// 	int c[1000];
// 	int count = 0; int count1 = 0;
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 		if (a[i] >= 0) {
// 			b[count] = a[i];
// 			count++;
// 		}
// 		else {
// 			c[count1] = a[i];
// 			count1++;
// 		}
// 	}
// 	cout << count << " " << count1 << endl;

// 	for (int i = 0; i < count; i++) {
// 		cout << b[i] << " ";
// 	}
// 	cout << endl;
// 	for (int i = 0; i < count1; i++) {
// 		cout << c[i] << " ";
// 	}
// 	cout << endl;
// 	sort(a, a + count);
// 	sort(a, a + count1);
// 	for (int i = 0; i < count; i++) {
// 		cout << b[i] << " ";
// 	}
// 	cout << endl;
// 	for (int i = 0; i < count1; i++) {
// 		cout << c[i] << " ";
// 	}
// 	cout << endl;
// 	int p = 0, q = 0;
// 	for (int i = 0; p < count && q < count1 ; i++) {
// 		cout << b[p] << " ";
// 		cout << c[q] << " ";
// 		p++;
// 		q++;
// 	}
// }



//Q. toggle k bits


// #include<iostream>
// using namespace std;
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n;
// 	cin >> n;
// 	int k;
// 	cin >> k;
// 	int ones = (-1);
// 	int mask = ~(ones << k);
// 	cout << (n ^ mask) << endl;
// }
//11 -2  10 2


// codezen rotation of bits
#include<iostream>
using namespace std;
void leftR(int n, int k) {
	int cnt = 0;
	int temp = n;

	while (temp != 0) {
		cnt++;
		temp = temp >> 1;
	}
	temp = n;
	int mask = temp >> (cnt - k);
	temp = temp << k;
	temp = (temp | mask);
	mask = (1 << cnt) - 1;
	temp = temp & mask;
	cout << temp << endl;
}
void rightR(int n , int k) {

	k = -k;
	int cnt = 0;
	int temp = n;
	int mask = temp >> k;
	while (temp != 0) {
		cnt++;
		temp = temp >> 1;
	}
	temp = n;
	temp = temp << (cnt - k);
	temp = temp | mask;
	mask = (1 << cnt) - 1;
	temp = (temp & mask);
	cout << temp << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int k; cin >> k;
	if (k > 0) {
		//means left rotation i.e.anti-clockwise rotation
		leftR(n, k);
	}
	else {
		rightR(n, k);
	}
}