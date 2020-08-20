/*
	PROBLEM : TOWER OF HANOI
*/
#include<iostream>
#include<cstring>
using namespace std;
void move(int n, char src, char helper , char dest) {
	// BASE CASE
	if (n == 0) {
		return;
	}

	//RECURSIVE CASE
	// MOVE (N-1) DISKS FROM SRC TO HELPER
	move(n - 1, src, dest, helper);
	cout << "Move Disk " << n << " from " << src << " to " << dest << endl;
	move(n - 1, helper, src, dest);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	// here : A- Source , B- Helper , C- Destination
	char A, B, C;
	move(n, 'A', 'B', 'C');
}
