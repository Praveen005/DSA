

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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char ch[100];
	cin >> ch;

	set<string>s;
	permute(ch, 0, s);
	for (auto str : s) {
		cout << str << endl;
	}

	set<int>a;
	for (int i = 0; i < 4; i++) {
		int k; cin >> k;
		a.insert(k);
	}
	for (auto p : a) {
		cout << p << endl;
	}


}