#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void replacePI(char* ch , int i) {
	if (ch[i] == '\0'  or ch[i + 1] == '\0') {
		return;
	}
	if (ch[i] == 'p' && ch[i + 1] == 'i') {
		int j = i;
		while (ch[j] != '\0') {
			j++;
		}
		while (j >= i + 2) {
			ch[j + 2] = ch[j];
			j--;
		}
		ch[i] = '3';
		ch[i + 1] = '.';
		ch[i + 2] = '1';
		ch[i + 3] = '4';
		replacePI(ch, i + 4);
	}
	else {
		replacePI(ch, i + 1);
	}



}
int main() {
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/
	int t; cin >> t;
	cin.get();
	while (t--) {
		char ch[10050];
		cin.getline(ch, 10050);
		int n = strlen(ch);
		int i = 0;
		replacePI(ch, i);
		cout << ch << endl;
	}
}


/*

	// alternate way


#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {

	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		string word = "pi";


		int index = s.find(word);
		int len = 2;
		s.erase(index, len);
		s.insert(index, "3.14");

		cout << s << endl;
	}

}

*/