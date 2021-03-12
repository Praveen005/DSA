/*
	Method that we adopted earlier(ref: DSA/CB/recursion/Permutation.cpp) to print all the possible permutations of a string will 
	give many redundant permutations for input like "ABA"

	EX: From previous approach: output: ABA, AAB,BAA,BAA,ABA,AAB
	
	Following approach will give only unique permutations
	output: AAB, ABA,BAA
	

	for more on set : ref: https://www.cplusplus.com/reference/set/set/
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;
void permute(char ch[], int i, set<string> &s) {
	if (ch[i] == '\0') {
		string str(ch);
		s.insert(str);
	}

	// rec case

	for (int j = i; ch[j] != '\0'; j++) {
		swap(ch[i], ch[j]);
		permute(ch, i + 1, s);
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
	char ch[100];
	cin >> ch;

	set<string>s;
	permute(ch, 0, s);

	for (auto str : s) {
		cout << str << endl;
	}

}
