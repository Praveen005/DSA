// //finding deteminant value of a matrix
// #include <iostream>
// using namespace std;
// #define N 3
// void cofactor( int a[N][N], int temp[N][N], int row , int col , int n ) {

// 	int t = 0, p;
// 	for (int i = 0; i < n; i++) {
// 		p = 0;
// 		for (int j = 0; j < n; j++) {
// 			if (i != row  && j != col) {
// 				//cout << "i= " << i << " j= " << j << endl;
// 				temp[t][p] = a[i][j];
// 				p++;

// 			}
// 		}
// 		if (p != 0)
// 			t++;
// 	}


// }

// int det(int a[N][N] , int n) {
// 	if (n == 1) {
// 		return a[0][0];
// 	}
// 	int temp[N][N];
// 	int f = 1;
// 	int d = 0;

// 	for (int i = 0; i < n; i++) {
// 		cofactor(a, temp, 0, i, n);
// 		d += f * a[0][i] * det(temp, n - 1);
// 		f = -f;
// 	}
// 	return d;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


// 	int a[N][N];
// 	for (int row = 0; row < N; row++) {
// 		for (int col = 0; col < N; col++) {
// 			cin >> a[row][col];
// 		}
// 	}
// 	for (int row = 0; row < N; row++) {
// 		for (int col = 0; col < N; col++) {
// 			cout << a[row][col] << " ";
// 		}
// 		cout << endl;
// 	}
// 	cout << det(a, N) << endl;

// }



#include <stdio.h>
#define N 3
void cofactor( int a[N][N], int temp[N][N], int row , int col , int n ) {

	int t = 0, p;
	int i, j;
	for ( i = 0; i < n; i++) {
		p = 0;
		for (int j = 0; j < n; j++) {
			if (i != row  && j != col) {
				temp[t][p] = a[i][j];
				p++;

			}
		}
		if (p != 0)
			t++;
	}


}
int det(int a[N][N] , int n) {
	if (n == 1) {
		return a[0][0];
	}
	int temp[N][N];
	int f = 1;
	int detValue = 0;
	int i;
	for ( i = 0; i < n; i++) {
		cofactor(a, temp, 0, i, n);
		detValue += f * a[0][i] * det(temp, n - 1);
		f = -f;
	}
	return detValue;
}
int main() {
	int a[N][N];
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			scanf("%d", &a[row][col]);
		}
	}
	printf("%d\n", det(a, N));
}





// 4 .   https://ide.geeksforgeeks.org/Y26Ji8rNsy
// 1.    https://ide.geeksforgeeks.org/6EZjqg7FIZ

// 3.   https://ide.geeksforgeeks.org/skReyxXaPk
// 2'   https://ide.geeksforgeeks.org/PTurPhZKOA
