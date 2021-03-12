/*
	Input : arr[]   = {1, 2, 3};
    query[] = {5, 3, 8}
	Output : Yes, Yes, No
	There is a subset with sum 5, subset is {2, 3}
	There is a subset with sum 3, subset is {1, 2}
	There is no subset with sum 8.

	Input : arr[] = {4, 1, 5};
    query[] = {7, 9}
	Output : No, Yes
	There is no subset with sum 7.
	There is a subset with sum 9, subset is {4, 5}

*//*
//my approach
#include<iostream>
#include<bitset>
using namespace std;
bool  check(int * a, int n, int q) {
	int c = (1 << n);
	for (int i = 0; i <= c; i++) {
		int no = i;
		int sum = 0;
		int l = 0;
		while (no > 0) {

			if ((no & 1) > 0) {
				sum += a[l];
			}
			no = no >> 1;
			l++;
		}
		if (sum == q) {
			return true;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {3, 1, 5};
	int q[] = {8, 7};
	int m = sizeof(q) / sizeof(q[0]);
	int n = sizeof(a) / sizeof(a[0]);
	int c = (1 << n);
	for (int i = 0; i < m; i++) {
		if (check(a, n, q[i])) {
			cout << "yes, ";
		}
		else {
			cout << "No, ";
		}
	}

}

*/

//geeks for geeks

// // C++ program to answer subset sum queries using bitset
// #include <iostream>
// #include<bitset>
// using namespace std;


// # define MAXSUM 10000


// void processQueries(int query[], int nq, bitset<MAXSUM> bit)
// {

// 	for (int i = 0; i < nq; i++)
// 	{
// 		int x = query[i];


// 		if (x >= MAXSUM)
// 		{
// 			cout << "NA, ";
// 			continue;
// 		}


// 		bit[x] ? cout << "Yes, " : cout << "No, ";
// 	}
// }


// void preprocess(bitset<MAXSUM> &bit, int arr[], int n)
// {

// 	bit.reset();

// 	bit[0] = 1;

// 	for (int i = 0; i < n; ++i){

// 		bit |= (bit << arr[i]);
// }


// int main()
// {
// 	int arr[] = {3, 1, 5};
// 	int query[] = {8, 7};

// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int nq = sizeof(query) / sizeof(query[0]);

// 	bitset<MAXSUM> bit;

// 	preprocess(bit, arr, n);
// 	processQueries(query, nq, bit);

// 	return 0;
// }


// self try
#include<iostream>
#include<bitset>
using namespace std;
#define MAX 100
void subset_sum_check(bitset<MAX>d, int* q, int m) {
	for (int i = 0; i < m; i++) {
		if (d[q[i]]) {
			cout << "Yes !" << endl;
		}
		else {
			cout << "NA" << endl;
		}
	}
}
void bitArr(bitset<MAX>&b, int *a, int n) {
	b.reset();
	b[0] = 1;
	for (int i = 0; i < n; i++) {

		b |= (b << a[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	bitset<MAX>b;
	int a[] = {3, 1, 5};
	int n = sizeof(a) / sizeof(a[0]);

	int q[] = {8, 7};
	int m = sizeof(q) / sizeof(q[0]);
	bitArr(b, a, n);

	subset_sum_check(b, q, m);
}
