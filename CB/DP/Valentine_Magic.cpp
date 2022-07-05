//problem link:  https://hack.codingblocks.com/app/contests/1338/281/problem

//#include <bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<math.h>
#include<cstring>
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

ll dp[5005][5005];
ll n, m;

ll b[5005], g[5005];


ll solve(int i, int j) {

    //base case

    //means we have paired all the boys
    if (i == n) {
        return 0;
    }

    //means we have rejected many girls and there is no girl to choose from
    //This isn't a favourabale config. so we return max value, as at the end it will get rejected in min() function
    if (j == m) {
        return INF;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    //recursive case
    //2 options we have

    ll op1 = abs(b[i] - g[j]) + solve(i + 1, j + 1); //chose the jth girl

    ll op2 = solve(i, j + 1); // not choosing the jth girl and call on the remaining girls' array

    return dp[i][j] = min(op1, op2);
}







int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    auto clk = clock();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }

    memset(dp, -1, sizeof(dp));

    sort(b, b + n);
    sort(g, g + n);


    // using Top down dp
    // initially the arguments are 0,0 because we starting from zeroth boy and zeroth girl.
    ll ans = solve(0, 0);
    cout << ans << endl;



    clk = clock() - clk;
    return 0;
}
