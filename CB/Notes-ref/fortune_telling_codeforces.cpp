#include<iostream>
#include<climits>
using namespace std;
void maxPetals(int a[], int n, int evenSum, int evenCount , int oddSum , int oddCount, int oddMin) {
	if (oddCount % 2) {
		cout << evenSum + oddSum << endl;
		return;
	}
	if (oddCount == 0) {
		cout << 0 << endl;
		return;
	}
	if (oddCount % 2 == 0) {
		cout << evenSum + oddSum - oddMin << endl;
		return;
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a[1000];
	int sum = 0;
	int oddCount = 0;
	int evenCount = 0;
	int evenSum = 0, oddSum = 0;
	int oddMin = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] % 2) {
			oddCount++;
			oddSum += a[i];
			oddMin = min(oddMin, a[i]);
		}
		else {
			evenCount++;
			evenSum += a[i];
		}
	}
	maxPetals(a, n, evenSum, evenCount, oddSum, oddCount, oddMin);


}