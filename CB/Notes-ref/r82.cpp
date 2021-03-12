#include <iostream>
#include<climits>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
bool func(int*a, int n, int i) {

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            if (a[i] != gcd(a[i], i + 1)) {
                return false;
            }
        }
    }
    return true;
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
    int a[100005];
    int sum;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

        }

        bool ans = func(a, n, 0);
        if (!ans) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
