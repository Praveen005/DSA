/*

	Problem: https://www.hackerrank.com/contests/agneevars-one/challenges/constant-difference/problem

*/



#include<iostream>
#include<bitset>
#include<cstdlib>
using namespace std;
bitset<100005>b;

bool check(int arr[], int n, int num) {
    if (num > 0 && num <= n) {
        return true;
    }
    return false;
}
bool func(int arr[], int n, int k, int i, int j) {
    if (i == n) {
        return true;
    }

    
    int num = j - k;
    if (check(arr, n, num) and b[num] == 1) {
        arr[i] = j - k;
        b[num] = 0;
        bool see = func(arr, n, k, i + 1, j + 1);
        if (see) {
            return true;
        }
    }
    arr[i] = 0;
    num = j + k;
    if (check(arr, n, num) and b[num] == 1) {
        arr[i] = j + k;
        b[num] = 0;
        bool see = func(arr, n, k, i + 1, j + 1);
        if (see) {
            return true;
        }
    }
    return false;
}

int main() {

    int t; cin >> t;
    while (t--) {
        b.set();
        int n, k; cin >> n >> k;
        int arr[100009] = {0};
        bool ans = func(arr, n, k, 0, 1);
        if (ans) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }

    }


}
