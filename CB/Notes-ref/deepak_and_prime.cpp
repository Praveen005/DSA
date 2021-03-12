#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long
const ll N = 9000000;
bitset<N>b;
vector<ll>primes;
void sieve(void) {
    b[0] = b[1] = 0;
    b[2] = 1;
    primes.push_back(2);
    for (ll i = 3; i <= N; i += 2) {
        b[i] = 1;
    }
    for (ll i = 3; i <= N; i += 2) {
        if (b[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= N; j += i) {
                b[j] = 0;
            }
        }
    }
}
int  main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    ll n; cin >> n;
    cout << primes[n - 1] << endl;

}