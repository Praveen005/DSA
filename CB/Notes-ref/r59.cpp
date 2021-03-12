/*
    // tilling problem

*/
#include<iostream>
#include<cstring>
using namespace std;
int waytoReach(int n, int k) {
    if (n == 0) {
        return 1;
    }

    if (n < 0 ) {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= (k); ++i)
    {
        ans += waytoReach(n - i, k);
        /* code */
    }
    return ans;
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int k; cin >> k;
    // 'k' is max value of the jump i.e it can take jumps of 1-k steps
    cout << waytoReach(n, k) << endl;

}



