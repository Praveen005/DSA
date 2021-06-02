/*

for "(a+(b))" you may think Parentheses around 'b' is redundant but 'b' can be -ve as well and in such case you will need to have a pair of parentheses around it.

so check with your Problem statement and make necessary changes if required in -----(1) [ can keep it like,  (count<=1) ]



*/
#include<iostream>
#include<stack>
using namespace std;
#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

bool redundant(string str) {
	stack<char>s;
	s.push(str[0]);
	int n = str.length();
	for (int i = 1; i < n; i++) {
		char ch = str[i];
		if (ch != ')') {
			s.push(ch);
		}
		else {
			int count = 0;
			while (!s.empty() and s.top() != '(') {
				count++;
				s.pop();
			}
			s.pop();
			if (count == 0) {		//  -------(1)
				return true;
			}
		}

	}
	return false;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	CINT


	int t; cin >> t;  //Number of testcases
	while (t--) {
		string s;
		cin >> s;
		if (redundant(s)) {
			cout << "Duplicate\n";
		}
		else {
			cout << "Not Duplicate\n";
		}
	}
	return 0;
}




/*

smaple Input:

12
(((a+(b))+(c+d)))
((a+(b))+(c+d))
(((a+(b))+(c+d)))
((a+(b))+(c+d))
(((a+(b)))+(c+d))
((a+b)+(c+d))
((a+(b))+(c+d))
((a-b+c)+((a+d)+(d+e))+((f+d)+(f+e)))
((a-b+c)+(((a+d)+(d+e))+((f+d)+(f+e))))
((a-b+c)+((a+d)+(d+e))+(((f+d)+(f+e))))
(((a-b+c)+((a+d)+(d+e)))+((f+d)+(f+e)))
((a-b+c)+(((a+d)+(d+e)))+((f+d)+(f+e)))



sample output:

Duplicate
Not Duplicates
Duplicate
Not Duplicates
Duplicate
Not Duplicates
Not Duplicates
Not Duplicates
Not Duplicates
Duplicate
Not Duplicates
Duplicate


*/
