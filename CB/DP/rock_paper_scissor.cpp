/*
PROBLEM STATEMENT:
Given 'R' rocks , 's' Scissors and 'P' number of papers.

Rock kills scissor, scissor kills paper and paper kills rock

we are required to find the respective probabilities of rock being the only survivor,
scissor being the only survivor and paper being the only survivor




*/

//#include <bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<cstring>
#include<iomanip>
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

//3 dimensional DP to store the lone surviving probability for each value(state) of r, s & p
double DP[105][105][105];

void set_dp() {
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 105; k++) {
                DP[i][j][k] = -1.0;
            }
        }
    }
}


double Rock_wins(int r, int p, int s) {

    //Base case
    if (r == 0 || s == 0) {
        return 0.0;
    }
    if (p == 0) {
        return 1.0;
    }

    if (DP[r][p][s] != -1.0) {
        return DP[r][p][s];
    }

    double ret = 0.0;
    double tot = (r * p + p * s + r * s);

    //recursive case
    //3- fights are possible
    // R vs P , P vs S, R vs S

    ret += Rock_wins(r - 1, p, s) * ((r * p) / tot);
    ret += Rock_wins(r, p - 1, s) * ((s * p) / tot);
    ret += Rock_wins(r, p, s - 1) * ((r * s) / tot);

    DP[r][p][s] = ret;

    return DP[r][p][s];
}

double Paper_wins(int r, int p, int s) {

    //Base case
    if (p == 0 || r == 0) {
        return 0.0;
    }
    if (s == 0) {
        return 1.0;
    }

    if (DP[r][p][s] != -1.0) {
        return DP[r][p][s];
    }

    double ret = 0.0;
    double tot = (r * p + p * s + r * s);

    //recursive case
    //3- fights are possible
    // R vs P , P vs S, R vs S

    ret += Paper_wins(r - 1, p, s) * ((r * p) / tot);
    ret += Paper_wins(r, p - 1, s) * ((s * p) / tot);
    ret += Paper_wins(r, p, s - 1) * ((r * s) / tot);

    DP[r][p][s] = ret;

    return DP[r][p][s];
}

double scissor_wins(int r, int p, int s) {
    //Base case
    if (s == 0 || p == 0) {
        return 0.0;
    }
    if (r == 0) {
        return 1.0;
    }

    if (DP[r][p][s] != -1.0) {
        return DP[r][p][s];
    }

    double ret = 0.0;
    double tot = (r * p + p * s + r * s);

    //recursive case
    //3- fights are possible
    // R vs P , P vs S, R vs S

    ret += scissor_wins(r - 1, p, s) * ((r * p) / tot);
    ret += scissor_wins(r, p - 1, s) * ((s * p) / tot);
    ret += scissor_wins(r, p, s - 1) * ((r * s) / tot);

    DP[r][p][s] = ret;

    return DP[r][p][s];
    // return DP[r][p][s];
}





int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    auto clk = clock();


    int t; cin >> t;
    int r, p, s;
    while (t--) {
        cin >> r >> s >> p;
        set_dp();
        double ans1 = Rock_wins(r, p, s);
        set_dp();
        double ans2 = Paper_wins(r, p, s);
        set_dp();

        double ans3 = scissor_wins(r, p, s);
        cout << fixed << setprecision(9) << ans1 << " " << ans3 << " " << ans2;
        cout << endl;
    }





    clk = clock() - clk;
    return 0;
}


/*

sample input:
3
2 2 2
2 1 2
1 1 3


sample output
0.333333333 0.333333333 0.333333333
0.150000000 0.300000000 0.550000000
0.057142857 0.657142857 0.285714286

*/

