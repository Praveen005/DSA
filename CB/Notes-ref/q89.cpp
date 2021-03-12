//bit masking
//clearbit
//updatebit
//count no of set bits
#include<iostream>
using namespace std;
bool getbit(int n , int i) {
	int mask = (1 << i);
	return (n & mask);
}
void clearbit(int &n , int i) {
	int mask = ~(1 << i);
	n = (n & mask);
}
int clear1stfewbit(int n, int i) {
	int mask = (-1 << (i + 1));
	return (n & mask);
}
int clearrangeof bits(int n, int i , int j) {
	int a = (-1 << (j + 1));
	int b = ()
	        int mask =
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif

	int n; cin >> n;
	// //n = 3;
	// cout << getbit(n, 2) << endl;
	// clearbit(n, 2);
	// cout << n << endl;
	cout << clear1stfewbit(n, 1) << endl;
}