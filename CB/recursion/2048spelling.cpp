/*
	input : 2048  or any other number for that matter :xd (https://bit.ly/2Q0wWck )
	
	output: two zero four eight
*/


#include<iostream>
#include<cstring>
using namespace std;
char ch[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void printSpelling(int n) {
	if (n == 0) {
		return;
	}
	printSpelling(n / 10);
	int digit = n % 10;
	cout << ch[digit] << " ";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	printSpelling(n);
}
