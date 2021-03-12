//c++
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

// 	// we input an matrix whose inverse is to be found out
// 	int a[N][N];
// 	for (int row = 0; row < N; row++) {
// 		for (int col = 0; col < N; col++) {
// 			cin >> a[row][col];
// 		}
// 	}

// 	// we create tepm2  matrix, it is an matrix of cofactors
// 	int temp2[N][N];
// 	float cofMatrix[N][N];
// 	int sign = 1;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N ; j++) {
// 			cofactor(a, temp2, i, j, N);
// 			cofMatrix[i][j] = sign * det(temp2, N - 1);
// 			sign = -sign;
// 		}
// 	}
// 	// cout << endl << endl;
// 	// for (int row = 0; row < N; row++) {
// 	// 	for (int col = 0; col < N; col++) {
// 	// 		cout << cofMatrix[row][col] << " ";
// 	// 	}
// 	// 	cout << endl;
// 	// }

// 	// following loop is uded to find out the transpose of the matrix of the cofactors
// 	// i.e  the adjoint of the given matrix a[N][N]
// 	for (int row = 0; row < N; row++) {
// 		for (int col = 0; col < N; col++) {
// 			if (row < col)
// 				swap(cofMatrix[row][col], cofMatrix[col][row]);
// 		}

// 	}


// 	// cout << endl << endl;
// 	// for (int row = 0; row < N; row++) {
// 	// 	for (int col = 0; col < N; col++) {
// 	// 		cout << cofMatrix[row][col] << " ";
// 	// 	}
// 	// 	cout << endl;
// 	// }

// 	// Dvalue is the determinant value of the matrix we enterd
// 	int Dvalue = det(a, N);

// 	// cout << Dvalue << endl;

// 	// PRINTING THE inverse of matrix
// 	for (int row = 0; row < N; row++) {
// 		for (int col = 0; col < N; col++) {
// 			cout << cofMatrix[row][col] / 10 << "  ";
// 		}
// 		cout << endl;
// 	}
// }




//c program
// 3) WAP to compute the inverse of a 3x3 matrix.
#include <stdio.h>
#define N 3
void cofactor( int a[N][N], int temp[N][N], int row , int col , int n ) {

	int t = 0, p;
	for (int i = 0; i < n; i++) {
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
	int d = 0;

	for (int i = 0; i < n; i++) {
		cofactor(a, temp, 0, i, n);
		d += f * a[0][i] * det(temp, n - 1);
		f = -f;
	}
	return d;
}

void swap(float a[N][N] , int n) {
	int i , j ;
	int c;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < j) {
				c = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = c;
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// we input an matrix whose inverse is to be found out
	int a[N][N];
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			scanf("%d", &a[row][col]);
		}
	}

	// we create tepm2  matrix, it is a matrix of cofactors
	int temp2[N][N];
	float cofMatrix[N][N];
	int sign = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N ; j++) {
			cofactor(a, temp2, i, j, N);
			cofMatrix[i][j] = sign * det(temp2, N - 1);
			sign = -sign;
		}
	}
	// swapping to get the adjoint of the matrix
	swap(cofMatrix, N);

	// Dvalue is the determinant value of the matrix we enterd
	int Dvalue = det(a, N);

	// PRINTING THE inverse of matrix
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%0.2f   ", cofMatrix[row][col] / 10);

		}
		printf("\n");

	}
}
