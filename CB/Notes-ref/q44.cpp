//money change problem

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a, int b) {
	//cout << "comparing " << a << " and " << b << endl;
	return a < b;
}


int main() {
	int money = 188;
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(coins) / sizeof(int);
	sort (coins, coins + n , compare);
	for (int i = 0; i < n; i++) {
		cout << coins[i] << " ";
	}

	std::vector<int> vecOfNums{ 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	cout << endl << vecOfNums[0] << endl;

	vector< int > data = {100, 142, 138, 96, 32, 149};
	swap(data[2], data[5]);
	int val1 = *max_element(data.begin(), data.begin() + 3);
	int val2 = *max_element(data.begin() + 3, data.end());
	cout << min(val1, val2) << endl;

	string s = "bca";

	do {
		cout << s << ' ';
	} while (next_permutation(s.begin(), s.end()));

	cout << s;
	// auto lb = lower_bound(coins, coins + n, money) - coins;

	// cout << "lb = " << lb << endl;
	// cout << coins[lb] << endl;

	// auto ub = upper_bound(coins, coins + n, money) - coins;

	// cout << "ub = " << ub << endl;
	// cout << coins[ub] << endl;


}