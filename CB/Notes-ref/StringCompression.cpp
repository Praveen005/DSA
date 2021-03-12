
/*

Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

Input Format
A single String S

Constraints
1 < = length of String < = 1000

Output Format
The compressed String.

Sample Input
aaabbccds

Sample Output
a3b2c2d1s1

Explanation
In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.



*/








#include<iostream>
using namespace std;
int count = 1;
void shorten(char*ch, int i) {
	if (ch[i] == '\0') {
		cout << ch[i - 1] << count;
		return;
	}
	if (ch[i] != ch[i - 1]) {
		cout << ch[i - 1] << count;
		count = 0;
	}
	count++;
	shorten(ch, i + 1);
}
int main() {
	char ch[1005];
	cin >> ch;
	shorten(ch, 1);
}
