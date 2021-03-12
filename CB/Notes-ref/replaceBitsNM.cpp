#include<iostream>
using namespace std;
void clearBitsItoJ(int &n, int i, int j) {
	int ones = ~(0);
	int a = ones << (j + 1);
	int b = (1 << i ) - 1;
	int mask = a | b;
	n = n & mask;
}
void replaceBits(int &n, int m , int i, int j) {
	clearBitsItoJ(n, i, j);
	int mask = (m << i);
	n = n | mask;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n;
	cin >> n;
	int m; cin >> m;
	int i;
	int j;
	cin >> i >> j;
	replaceBits(n, m, i, j);
	cout << n << endl;

}