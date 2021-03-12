#include <iostream>
#include<climits>
using namespace std;
bool func(int*a, int n, int i, int sum) {
    if (i == n) {
        i = 0;
        // return false;
    }
    if (sum < 0) {
        return false;
    }
    if (sum == 0) {
        cout << "YES\n";
        return true;
    }

    if (func(a, n, i + 1, sum - (i + 1))) {
        return true;
    }

    if (func(a, n, i + 1, sum)) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    int a[100];
    int sum;
    while (t--) {
        int n;
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        bool ans = func(a, n, 0, sum);
        if (!ans) {
            cout << "NO\n";
        }

    }
}
