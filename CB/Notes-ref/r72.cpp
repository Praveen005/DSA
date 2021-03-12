#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int ans = 0;
void place(int in[][25], int n, int i, int j, int count) {
	if (i < 0 || i >= n || j < 0 || j >= n || in[i][j] == 0) {
		return;
	}
	in[i][j] = 0;
	ans = max(ans, count + 1);

	for (int k = 0; k < 8; k++) {
		int row = i + x[k];
		int col = j + y[k];
		place(in, n, row, col, count + 1);
	}
	in[i][j] = 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int sum = 0;
	int a[25][25];
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> a[row][col];
			if (a[row][col]) {
				sum++;
			}
		}
	}
	place(a, n, 0, 0, 0);

	cout << sum - ans << endl;
}
