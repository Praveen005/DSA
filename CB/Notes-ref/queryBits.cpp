/*
*	0 L R: Set all the bits from Lth bit to Rth bit to zero.

*	1 L R: Set all the bits from Lth bit to Rth bit to one.

*	2 L R: Find the integer formed by the bits in range [L, R]. Answer all the queries of type 2.

*	Indexing is 0-based.

*	1<=n,q<=200000 0<=L,R<n

*	3 6
	1 0 1
	2 0 2
	0 1 1
	2 1 1
	1 2 2
	2 0 2

*	6
	0
	5

*/
#include<iostream>
#include<bitset>
using namespace std;
const int MAX = 200009;
#define ll long long
void clearBit(int l, int r, int n, bitset<MAX>&b) {

	//b.reset();
	bitset<MAX>c;
	bitset<MAX>bs;
	bs.set();
	bs = (bs >> (r + 1));
	c.set();
	c = c << (MAX - l);
	bs = bs | c;
	b = (b & bs);




// TRIED HARD  BUT FAILED SEEMS I HAVE NOT READ THE TOPIC AS OF NOW.
	// ANYWAY  NICE TRY IT WAS

	//TLE !!




}
void setBit(int l, int r, int n, bitset<MAX>&b) {
//	b.reset();
	bitset<MAX>c;
	bitset<MAX>bs;
	bs.set();
	bs = (bs >> (r + 1));
	c.set();
	c = c << (MAX - l);
	bs = ~(bs | c);
	b = (b | bs);


}
void printNum(bitset<MAX>&b) {
	cout << b << "  ";
	cout << b.to_ullong() << endl;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int q; cin >> q;
	bitset<MAX>b;
	while (q--) {
		int type , l, r;
		cin >> type >> l >> r;
		if (type == 0) {
			clearBit(l, r, n, b);
		}
		else if (type == 1) {
			setBit(l, r, n, b);
		}
		else
		{
			ll sum = 0;
			for (int i = n - r - 1; i <= n - 1 - l; i++) {
				sum += b[MAX - 1 - (n - 1 - i)] * (1 << i);
			}
			//cout << b << "  ";
			cout << sum << endl;
		}
	}

}