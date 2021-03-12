//going for bit manipulation
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long
ll clearRange(ll n, ll i , ll j) {
	ll a = ((-1) << (j + 1));
	ll b = (1 << i) - 1;
	ll mask = (a | b);
	return (n & mask);
}
ll replace(ll n , ll m, ll i, ll j) {
	//cout << n << endl;
	n = clearRange(n, i, j);
	cout << n << endl;
	ll mask = (m << i);
	n = (n | mask);
	return n;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);

#endif
	//now will replace a few bits in n by m
	ll n;
	cin >> n;
	ll i , j;
	cin >> i >> j;
	ll m;
	cin >> m;
	cout << replace(n, m , i, j) << endl;
	//here i > j

}