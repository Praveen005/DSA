/*
	Permutation: using backtracking
*/
#include<iostream>
using namespace std;
void permute(char* ch, int i) {
	//Base case
	if (ch[i] == '\0') {
		cout << ch << endl;
		return;
	}
	// recursive case
	for (int j = i; ch[j] != '\0'; j++) {
		swap(ch[i], ch[j]);
		permute(ch, i + 1);
		//backtracking - to restore the original array
		swap(ch[i], ch[j]);
	}
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	char ch[1000];
	cin >> ch;
	permute(ch, 0);
}
