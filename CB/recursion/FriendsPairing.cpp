/*
	problem: Given N friends,who want to go for outing on bikes. Each guy can go as single or as a couple.
		find the number of ways in which N friends can go for outing.
		
		note: They have enough bikes for solo trip.

*/



#include<iostream>
#include<cstring>
using namespace std;
int GoForOuting(int n) {
//base case
	if (n == 0 || n == 1) {
		return 1;
	}
	int ans;
//recursive case
	ans = GoForOuting(n - 1) + (n - 1) * GoForOuting(n - 2);
	return ans;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	int n;
	cin >> n;
	cout << GoForOuting(n) << endl;

}
