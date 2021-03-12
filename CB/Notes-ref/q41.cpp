//max sum submatrix in a row and columnwise sorted matrix // CB's approach
#include<bits/stdc++.h>
using namespace std;
void maxSum(int ** arr , int n) {
	//row-wise addition
	for (int j = n - 1; j >= 0; j--) {
		for (int i = n - 2; i >= 0; i--) {
			arr[i][j] += arr[i + 1][j];

		}
	}
	//col wise adding
	for (int j = n - 1; j >= 0; j--) {
		for (int i = n - 2; i >= 0; i--) {
			arr[j][i] += arr[j][i + 1];

		}
	}
	int result = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(arr[i][j], result);
		}
	}
	cout << result << endl;

}

int main() {

	int n = 3;
	//cin>>n;
	int val = 1;
	//line 36-39 is the way to declare a 2D array dynamically
	//link :  https://www.tutorialspoint.com/How-do-I-declare-a-two-dimensional-array-in-Cplusplus-using-new
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cin>>a[i][j];
			arr[i][j] = val;
			val++;
		}
	}

	maxSum(arr, n);
}