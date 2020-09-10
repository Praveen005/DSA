/*
	You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.

Note:

All numbers (including target) will be positive integers
Elements in the combination must be in non-descending order
There should be no duplicate combinations

Input Format
The first line will contain N indicating the number of elements in the array.
The second line will contain space separated N integers , A[i].
The third line will contain the target number T.

Constraints
N <= 15 1<= A[I] <= 100

Output Format
Print all unique combinations of the numbers satisfying the above constraints in a separate line in lexicographic manner.

Sample Input

7
10 1 2 7 6 1 5
8

Sample Output
1 1 6 
1 2 5 
1 7 
2 6 



*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<vector<int>>set_of_vectors;

void func(int* arr, int n) {
	sort(arr, arr + n);
	vector<int>v;
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
	}
	set_of_vectors.insert(v);

}
void solve(int *a, int* out, int n, int target, int i, int j, int sum ) {
	//BASE CASE
	if (i == n) {
		if (sum == target) {
			
			int arr[100];
			for (int k = 0; k < j; k++) {
				arr[k] = out[k];
			}
			func(arr, j);
			sum = 0;
		}
		return;
	}
	if (sum > target) {
		return;
	}
	sum += a[i];
	out[j] = a[i];
	//Every element of the array has two options: Get selected/Not selected
	//selected
	solve(a, out, n, target, i + 1, j + 1, sum);
	//Backtrack
	sum -= a[i];
	//Not selected
	solve(a, out, n, target, i + 1, j, sum);


}
int main() {

	int n; cin >> n;
	int a[20];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int target; cin >> target;
	int out[20];

	solve(a, out, n, target, 0, 0, 0);

	for (auto it : set_of_vectors) {
		vector<int>v = it;
		for (auto it1 : v) {
			cout << it1 << " ";
		}
		cout << endl;
	}
}




