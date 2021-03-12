#include<iostream>
using namespace std;

void insertionSort(int a[] , int n) {
  for (int iteration = 0; iteration < n - 1; iteration++) {
    int j = iteration;
    int e = a[j + 1];
    while (j >= 0 && a[j] > e) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = e;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt" , "r" , stdin);
  freopen("output.txt" , "w" , stdout);
#endif
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  insertionSort(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }


}