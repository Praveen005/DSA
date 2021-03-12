// N-Queen problem using BitMasking

#include<iostream>
using namespace std;
int n, DONE;
int ans = 0;
void place(int rowMask, int ld, int rd) {
	if (rowMask == DONE) {
		ans++;
		return;
	}
	int safe = DONE & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		safe = safe - p;
		place((rowMask | p), ((ld | p) << 1) , (rd | p) >> 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	int rowMask = 0, ld = 0, rd = 0;
	DONE = (1 << n) - 1;
	place(rowMask, ld, rd);
	cout << ans << endl;



}