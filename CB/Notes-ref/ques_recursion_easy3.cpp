//Q1. recursive function to perform binary search
#include<iostream>
using namespace std;
int BS(int a[],  int s, int e, int key) {
	int mid = (s + e) / 2;
	// base case
	if (a[mid] == key) {
		return mid;
	}
	if (s == e) {
		return -1;
	}
	else if (a[mid] > key) {
		return BS(a, 0, mid - 1, key);
	}
	else {
		return BS(a, mid + 1, e, key);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 2, 3, 4, 5, 10, 20};

	int n = sizeof(a) / sizeof(a[0]);

	cout << BS(a, 0, n - 1, 33) << endl;

}





//Q2. write a recursive method to find a^n


// #include<iostream>
// using namespace std;
// int power(int a, int n) {
// 	if (n == 1) {
// 		return a;
// 	}

// 	// or  if(n==0)  return 1;
// 	return a * power(a, n - 1);
// }


// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int a, n;
// 	cin >> a >> n;
// 	cout << power(a, n);
// }




//Q3. write arecursive function to multiply two numbers without using *operator

// #include<iostream>
// using namespace std;
// int sum(int a, int b) {
// 	// if (b == 1) {
// 	// 	return a;
// 	// }  or

// 	if (b == 0) {
// 		return 0;
// 	}
// 	return a + sum(a, b - 1);
// }


// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a, b;
// 	cin >> a >> b;
// 	cout << sum(a, b);
// }

//done