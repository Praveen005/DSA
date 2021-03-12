//largest string
//one way using character array.
//using strcpy()     :)
#include<iostream>
#include<cstring>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n;
	cin >> n;
	char ch[1000];

	cin >> ch;
	char largest[1000];
	int large;
	int max = 0;
	strcpy(largest, ch);
	for (int i = 0; i < n ; i++) {

		cin.getline(ch, 1000, '\n');
		large = strlen(ch);
		if (max < large) {
			max = large;
			strcpy(largest , ch);
		}


	}
	cout << largest << endl;
}