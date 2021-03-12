
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long
const ll N = 90000000;
bitset<N>b;
vector<int>primes;
void primeFinding(void) {
	b[0] = b[1] = 0;
	b[2] = 1;
	primes.push_back(2);
	for (int i = 3; i <= N; i += 2) {
		b[i] = 1;
	}
	for (ll i = 3; i <= N; i += 2) {
		if (b[i] == 1) {
			primes.push_back(i);
			for (ll j = i * i; j <= N; j += i) {
				b[j] = 0;
			}
		}
	}
}
/*
Input:
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863
*/
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	primeFinding();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		cout << primes[num - 1] << endl;
	}

}
