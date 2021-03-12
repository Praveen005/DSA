/*bit manipulation basics  : order of operation
*
* checking whether a no. is even or odd
* get the bit at ith position
* set the bit at ith position
* clear the bit at ith position
* update bit at ith position
*
*/
#include <iostream>
#include<algorithm>
using namespace std;
int checkno(int n) {
	if ((n & 1) == 1) {
		cout << "odd" << endl;
	}
	else {
		cout << "even" << endl;
	}

}
int getbit(int n , int i) {
	int mask = (1 << i);
	return (n & mask) > 0 ? 1 : 0 ;
}


int setBit(int n, int i) {
	int mask = (1 << i);
	return ( n | mask );
}

void clearBit(int &n , int i) {
	int mask = ~(1 << i);
	n = (n & mask);

}
void updateBit(int &n, int i , int v) {
	int mask = ~(1 << i); //cleared the bit at ith position
	int cleared_no = n & mask;
	n = cleared_no | (v << i);
}

int clearLastIBits(int n, int i) {
	int mask = (-1 << i);
	return n &  mask;
}

void clearRangeItoJ(int &n, int i, int j) {
	int ones = -1;
	int a = ones << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;
}



int main() {



#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	// int n; cin >> n;
	// // 1st operation
	// checkno(n);
	// //2nd operation
	// int x = getbit(6, 2);
	// cout << x << endl;
	// //3rd operation
	// cout << setBit(n , 2) << endl;
	// //4th operation
	// //clearBit(n , 3);
	// cout << n << endl;
	// updateBit(n, 0, 1);
	// cout << n << endl;

	// int n = 15;
	// int i = 2;
	// cout << clearLastIBits(n, i) << endl;
	int n = 31;
	int i = 1, j = 3;
	clearRangeItoJ(n, i, j);
	cout << n << endl;

}
