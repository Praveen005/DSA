//  print all unique combinations in the array whose sum equals the target number
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
			/*
				if you sort the array here then gadbad will happen
				what Gadbad??

				suppose array is 5 1 1 and target 6
				output array out[] be 5,1

				next time when you return back to previous function call and
				sum-=a[i]  means  sum=5
				do out[i]=a[i]
				then in place of 1 some 1 will be written, which is OK. sum=6

				but if you sort it(output array, out[]) here then it will become 1 5
				and 5 will get overwritten by 1 sum-=1:: sum=5
				output: 1 1  :wrong
			*/
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
	solve(a, out, n, target, i + 1, j + 1, sum);
	sum -= a[i];
	solve(a, out, n, target, i + 1, j, sum);


}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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


