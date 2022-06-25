
//Problem link:   https://codeforces.com/problemset/problem/682/D

//#include <bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<climits>
#include<cstring>
#include<math.h>
using namespace std;


#define ll long long

#define endl '\n'


#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mod = 1e9 + 7;


const long long INF = 2e18 + 10;
// const int INF=1e9+10;


const double pi = acosl(-1);


#define stp cout << fixed << setprecision(20);

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

int n, m, k;
string s, t;
int dp[1005][1005][12][2];

int max_length_sum(int is, int it, int rem, int cont) {
    //Base Case

    if (is == n || it == m) {
        return ((rem == 0) ? 0 : INT_MIN);
    }
    if (rem == 0) {
        return 0;
    }

    if (dp[is][it][rem][cont] != -1) {
        return dp[is][it][rem][cont];
    }

    int ret = INT_MIN;

    //4 cases arise
    // skip the current character in 's'
    // skip the current charcater in 't'
    // add 1 to the answer, since s[is]== t[it]
    // though s[is]== t[it], still skip current character in both 's' and 't'
    // Because we need exactly k substrings(k strings bhi pura karna hai na)
    //It may happen that though p1 is lomg enough but we still need to break it into
    // two or more in order to get k sub-strings


    ret = max(ret, max_length_sum(is + 1, it, rem - cont, 0));
    ret = max(ret, max_length_sum(is, it + 1, rem - cont, 0));

    if (s[is] == t[it]) {
        ret = max(ret, 1 + max_length_sum(is + 1, it + 1, rem, 1));
        ret = max(ret, 1 + max_length_sum(is + 1, it + 1, rem - 1, 0));
    }
    return dp[is][it][rem][cont] = ret;

}






int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    auto clk = clock();

    cin >> n >> m >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << max_length_sum(0, 0 , k, 0) << endl;







    clk = clock() - clk;
    return 0;
}
