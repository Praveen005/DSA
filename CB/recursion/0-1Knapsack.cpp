/*
	0-1 knapsack problem
*/
#include<iostream>
#include<cstring>
using namespace std;
int profit(int* wt, int* prices, int N, int capacity) {
	if (N == 0 || capacity == 0) {
		return 0;
	}
	int ans = 0;
	int inc = 0, exc = 0;
	if (wt[N - 1] <= capacity) {

		inc = prices[N - 1] + profit(wt, prices, N - 1, capacity - wt[N - 1]);
	}
	exc = profit(wt, prices, N - 1, capacity);

	ans = max(inc, exc);
	return ans;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	int wt[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};
	int N = 4;
	int c = 6; //capacity of bag
	cout << profit(wt, prices, N, c) << endl;

}
