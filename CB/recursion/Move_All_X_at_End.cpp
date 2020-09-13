/*

Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end.
E.g. for “abexexdexed” return “abeedeedxxx”.
Print the value returned


Input Format
Single line input containing a string


Constraints
Length of string <= 1000


Output Format
Single line displaying the string with all x's moved at the end


Sample Input
axbxc

Sample Output
abcxx

Explanation
All x's are moved to the end of string while the order of remaining characters remain the same.




*/



#include<iostream>
#include<cstring>
using namespace std;
void move(char*ch, int i, int j) {
	if (i >= j) {
		return ;
	}
	if (i == strlen(ch) - 1) {
		move(ch, 0, j - 1);
	}
	if (ch[i] == 'x') {
		swap(ch[i], ch[i + 1]);
		move(ch, i + 1, j);
	}
	move(ch, i + 1, j);

}


int main() {
	char ch[1005];
	cin >> ch;
	int n = strlen(ch);
	move(ch, 0, n - 1);
	cout << ch << endl;
}
