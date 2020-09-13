/*



Take as input str, a string. Write a recursive function which returns all the words possible by rearranging the characters of this string which are in dictionary order smaller than the given string. The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 25

Output Format
Display all the words which are in dictionary order smaller than the string entered in a new line each. The output strings must be sorted.

Sample Input
cab

Sample Output
abc
acb
bac
bca

Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only four of them are lexicographically less than "cab". We print them in lexicographical order.

*/




#include<iostream>
#include<cstring>
#include<set>
using namespace std;
set<string>s;
string chr;
void permute(char*ch, int i) {
	if (ch[i] == '\0') {
		string ss = ch;
		if (ss < chr)
			s.insert(ss);
		
		return;
	}

	for (int k = i; ch[k] != '\0'; k++) {
		swap(ch[i], ch[k]);
		permute(ch, i + 1);
		swap(ch[i], ch[k]);
	}
}

int main() {

	char ch[30];
	cin >> ch;
	chr = ch;
	char out[25];
	permute(ch, 0);
	for (auto x : s) {
		cout << x << endl;
	}
}
