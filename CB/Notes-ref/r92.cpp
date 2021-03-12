#include<iostream>
#include <cstdlib>
#include<cstring>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
const int N = 1000000;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//Dynamic memory allocation

	//2-D array

	int** var = new int*[5];
	for (int i = 0; i < 5; i++) {
		var[i] = new int[10];
	}

	for (int i = 0; i < 5; i++) {
		delete []var[i];
	}
	delete [] var;
}