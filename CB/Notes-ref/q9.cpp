// string class revision
#include<iostream>
#include<string>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "pratyush is a bad boy";
	string s2 = " ram is also good";
	cout << s1 << endl << s2 << endl << s1 + s2;
	string s3 = "123";
	string s4 = "567";
	cout << endl << s3 + s4 << endl;
	s1.append(" but sometimes good :)");
	cout << s1 << endl;
	s1.clear();
	cout << "s1 = " << s1 << endl;
	s1.append("Anamika is a good girl");
	cout << s1 << endl;
	string word = "good ";
	int index = s1.find("good ");
	int index1 = s1.find("good");
	string word1 = "good";
	int length1 = word1.length();
	cout << "length1 " << length1 << endl << "index1 " << index1 << endl;
	int length = word.length();
	cout << "index " << index << endl;
	cout << "length " << length << endl;
	s1.erase(index, length);
	cout << s1 << endl;

	cout << s1.compare(s2) << endl;
	for (int i = 0; i < s1.length(); i++) {
		cout << s1[i] << ":";
	}
	cout << endl;

	for (string::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << ":";
	}
	cout << endl;

	for (auto it = s1.begin(); it != s1.end(); it++) {
		cout << *it << ":";
	}

}