#include<iostream>
#include<vector>
#include<climits>
#define FOR(i,a,b) 	for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a; i<=b; i++)
#define PB push_back
#define MP make_pair
#define w(t) while(t--)
#define ll long long
using namespace std;
void merge(int a[], int s, int e) {
	int temp[100];
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++) {
		a[i] = temp[i];
	}
}
void mergesort(int a[], int s, int e) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	mergesort(a, s, mid);
	mergesort(a, mid + 1, e);
	merge(a, s, e);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[100];
	FOR(i, 0, n) {
		cin >> a[i];
	}
	mergesort(a, 0, n - 1);
	FOR(i, 0, n) {
		cout << a[i] << " ";
	}

}