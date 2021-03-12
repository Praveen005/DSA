// #include<iostream>
// using namespace std;
// int locc(int a[], int n, int key) {
// 	if (n == 0) {
// 		return -1;
// 	}
// 	int i = locc(a + 1, n - 1, key);
// 	if (i == -1) {
// 		if (a[0] == key) {
// 			return 0;
// 		}
// 		else {
// 			return -1;
// 		}
// 	}
// 	return i + 1;

// }
// int focc(int *a, int n, int key) {
// 	if (n == 0) {
// 		return -1;
// 	}
// 	if (a[0] == key) {
// 		return 0;
// 	}
// 	int i = focc(a + 1, n - 1, key);
// 	if (i == -1) {
// 		return -1;
// 	}
// 	return i + 1;

// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	// linear search of a key in an array
// 	int a[] = {1, 2, 3, 4, 5, 4, 6, 4, 8};
// 	//will look for first and last occurance
// 	int n = sizeof(a) / sizeof(a[0]);
// 	cout << n << endl;
// 	cout << focc(a, n, 4) << endl;
// 	cout << locc(a, n, 4) << endl;
// 	//correct till this point

// }

// finding all the occurances of a key in an array
#include<iostream>
using namespace std;
int storeOcc(int a[], int i, int n, int j, int *output, int key) {
	// this program actually returns the sizwe of the output array
	//base case
	if (i == n) {
		return j;
	}
	if (a[i] == key) {
		output[j] = i;
		return storeOcc(a, i + 1, n, j + 1, output, key);
	}
	return storeOcc(a, i + 1, n, j, output, key);

}
void allocc(int *a, int i, int n, int key) {
	if (i == n) {
		return;
	}
	if (a[i] == key) {
		cout << i << endl;

	}
	allocc(a , i + 1, n, key);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 2, 3, 4, 5, 4, 6, 4, 7, 4, 9};
	int n = sizeof(a) / sizeof(a[0]);
	//cout << n << endl;
	int key = 4;
	//allocc(a, 0, n, key);
	int output[100];
	int cnt;
	cnt = storeOcc(a, 0, n, 0, output, key);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << output[i] << " ";
	}
}

