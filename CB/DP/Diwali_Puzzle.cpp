//problem link: https://hack.codingblocks.com/app/contests/2095/1262/problem

//#include <bits/stdc++.h>
#include<iostream>
#include<ctime>
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

#define mod 1000003

//Memoization helps in storing the values of differet statesm, so that one does not
//get to calculate one state again

ll dp[105][3][105];
ll n, k;

//i: current index we are at
//prev: value(0/1) at the previous index
//cnt: what is the current sum of product
ll solve(ll i, ll prev, ll cnt) {
    // cout << "n: " << n << "  k: " << k << endl;
    //Base case
    if (i == n) {
        if (cnt == k) {
            return 1;
        }
        return 0;
    }

    if (dp[i][prev][cnt] != -1) {
        return dp[i][prev][cnt];
    }

    ll ans = 0;

    //rec case
    //putting 1 at the current index
    if (prev == 1) {
        ans += solve(i + 1, 1, cnt + 1);
    }
    else {
        ans += solve(i + 1, 1, cnt);
    }

    ans = (ans % mod);
    //putting 0 at the current index

    ans += solve(i + 1, 0, cnt);
    ans %= mod;

    return dp[i][prev][cnt] = ans;
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    auto clk = clock();

    int t; cin >> t;
    // memset(dp, -1, sizeof(dp));


    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << (solve(1, 0, 0) + solve(1, 1, 0)) % mod << endl;
    }






    clk = clock() - clk;
    return 0;
}

/*

We first fill the array with 0s / 1s till the very last and then see if the sum of product is equal to k.
If it is greater or less than 'k' then that is not our answer.

It might be tempting to think, ki jahan tak sum 'k' ke equal ho jata hai, wahan tak chhod dete hain aur
baki bache positions(if any) par 0 likh denge.
but we won't do that, cz iss se jo aap combination banane ki sonch rahe ho wo already ban jaayega, dusre functional call
se, aur aap aisa karoge to repetition hoga.

This is why at the end(at i==n) we are checking if cnt== k or not.

hope your confusion is cleared
*/
