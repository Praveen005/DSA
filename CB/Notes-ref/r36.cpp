// #include<iostream>
// using namespace std;
// #define ll long long
// void modExponent(ll a, ll b , ll c) {
//     ll x = (a % c), res = 1;
//     while (b > 0) {
//         if (b & 1) {
//             res = (res * x) % c;
//         }
//         b = b >> 1;
//         x = (x * x) % c;
//     }
//     cout << res << endl;
// }
// ll main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ll a, b, c;
//     cin >> a >> b >> c;
//     modExponent(a, b, c);

// }

// above is iterative approach
// below one is better and a recursive approach

#include<iostream>
using namespace std;
#define ll long long
ll modExponent(ll a, ll b , ll c) {
    if (a == 0) {
        return 0;
    }
    else if (b == 0) {
        return 1;
    }
    else if (b % 2) {
        ll k = a % c;
        return (k * modExponent(a, b - 1, c)) % c;
    }
    else {
        ll y = modExponent(a, b / 2, c);
        return (y * y) % c;
    }

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a, b, c;
    cin >> a >> b >> c;
    cout << modExponent(a, b, c);

}