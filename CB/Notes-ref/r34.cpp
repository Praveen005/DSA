#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

const int N = 100005;
char a[N];
int opp[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k, i, cnt = 0;
	cin >> n >> k >> a;
	for (i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i]) {
			a[i] = a[n - 1 - i] = (max(a[i], a[n - 1 - i]));
			opp[i] = 1;
			cnt++;
		}

	for (i = 0; i < n / 2 && cnt < k; i++)
		cout << cnt << " ";
	if (a[i] != '9') {
		if (opp[i] > 0 || cnt + 2 <= k) {
			a[i] = a[n - 1 - i] = '9';
			cnt += 2 - opp[i];
			cout << cnt << endl;
		}
	}

	if (n % 2 == 1 && cnt < k)
		a[n / 2] = '9';

	if (cnt <= k)
		cout << a;
	else
		cout << "-1";


}