// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<bitset>
// using namespace std;
// #define ll long long
// const int N = 1000005;
// vector<int> primes;
// bitset<N>b;
// void sieve(void) {
//     b.reset();
//     b[0] = b[1] = 0;
//     b[2] = 1;
//     primes.push_back(2);
//     for (int i = 3; i <= N; i += 2) {
//         b[i] = 1;
//     }
//     for (ll i = 3; i <= N; i += 2) {
//         if (b[i] == 1) {
//             primes.push_back(i);
//             for (ll j = (i * i); j <= N; j += i) {
//                 b[j] = 0;
//             }
//         }
//     }
// }
// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     sieve();
//     int t;
//     cin >> t;
//     while (t--) {
//         int a, b1;
//         cin >> a >> b1;
//         int n1;
//         int count = 0;
//         for (int i = a; i <= b1; i++) {
//             n1 = upper_bound(primes.begin(), primes.end(), i) - primes.begin();
//             if (b[n1] == 1) {
//                 count++;
//             }
//         }
//         cout << count << endl;
//     }
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<bitset>
// using namespace std;
// #define ll long long
// const int N = 1000005;
// vector<int> primes;
// bitset<N>b;
// void sieve(void) {
//     b.reset();
//     b[0] = b[1] = 0;
//     b[2] = 1;
//     primes.push_back(2);
//     for (int i = 3; i <= N; i += 2) {
//         b[i] = 1;
//     }
//     for (ll i = 3; i <= N; i += 2) {
//         if (b[i] == 1) {
//             primes.push_back(i);
//             for (ll j = (i * i); j <= N; j += i) {
//                 b[j] = 0;
//             }
//         }
//     }
// }
// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     sieve();
//     int t;
//     cin >> t;
//     bitset<N>b2;
//     b2 = b;

//     while (t--) {
//         int a, b1;
//         cin >> a >> b1;
//         int n1;
//         int count = 0;
//         b2 = b;
//         for (int i = a; i <= b1; i++) {
//             b2 = b;
//             b2 = (b2 << (N - 1 - i));
//             n1 = b2.count();
//             if (b[n1] == 1) {
//                 count++;
//             }
//         }
//         cout << count << endl;
//     }
// }


// in above two programs i have complicated the things which resulted in TLE


#include<iostream>
using namespace std;
#define ll long long
const int N = 1000005;
int a[N] = {0};
int cumSum[N] = {0};
int cum[N];
void sieve() {
    a[0] = a[1] = 0;
    a[2] = 1;
    int cnt1 = 1;
    for (int i = 3; i <= N; i += 2) {
        a[i] = 1;
    }
    for (ll i = 3; i <= N; i += 2) {
        if (a[i]) {
            for (ll j = i * i; j <= N; j += i) {
                a[j] = 0;
            }
        }
    }

    //we are done with sieve
    //ARRAY THAT HOLDS NO OF PRIMES PRESENT BEFORE I
    int sum = 0, cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (a[i]) {
            cnt++;
            sum ++;
        }
        cumSum[i] = sum;

    }
    // CUMULATIVE SUM OF REQUIRED COUNT
    // THIS CUMULATIVE  SUM ARRY REDUCED THE TIME BY AROUND 1/10th
    int csum = 0;
    cum[0] = 0;
    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1];
        if (a[cumSum[i]]) {
            cum[i]++;

        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int a1, b;
        cin >> a1 >> b;
        cout << cum[b] - cum[a1 - 1] << endl;
    }
}