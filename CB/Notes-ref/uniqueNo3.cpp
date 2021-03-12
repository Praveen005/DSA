// unique no III
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n;
	cin >> n;
	int no;
	//fixed size of array means O(1) space
	int cnt[64] = {0};
	for (int i = 0; i < n; i++) {
		cin >> no;
		int j = 0;
		while (no > 0) {
			int last_bit = (no & 1);
			cnt[j] += last_bit;
			j++;
			no = no >> 1;
		}
	}
	//divide cnt by 3 anf form the number
	int p = 1; int ans = 0;
	for (int i = 0; i < 64; i++) {
		cnt[i] = (cnt[i] % 3);
		ans += (cnt[i] << i);
		//p = p << 1;

	}
	cout << ans << endl;


}