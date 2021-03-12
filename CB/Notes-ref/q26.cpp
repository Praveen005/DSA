#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int key;
	cin >> key;
	char ch[100];
	cin >> ch;
	int n = strlen(ch);
	char fvalue ;
	char vvalue ;
	int check1 = 0, check2 = 0;
	if (ch[0] == 'a') {
		char fvalue = 'a';
		char vvalue = 'b';
	}
	else {
		vvalue = 'a';
		fvalue = 'b';
	}
	int max = 0;
	int f2 = 0;
	int f1 = 0, cnt1 = 0 , i = f1;
	while (f2 < n) {
		while (cnt1 < 3 && (i + 1) < n)  {
			if (ch[i + 1] == vvalue) {
				cnt1++;
			}
			i++;
			check1++;
			//	cout << "check1  " << check1 << endl;
		}

		if (cnt1 = 3) {
			f2 = i - 1;
		}
		else {
			f2 = i;
		}

		cnt1 = 0;
		i = f1;

		if (max < f2 - f1 + 1) {
			max = f2 - f1 + 1;
		}
		if (f2 = n - 1) {
			break;
		}
		while (cnt1 < 1   && (i + 1) < n) {
			if (ch[i + 1] == vvalue) {
				cnt1++;
			}
			i++;
			check2++;
			//	cout << "check2  " << check2 << endl;
		}

		f1 = i + 1; cnt1 = 0; i = f1;
		break;

	}
	cout << max << endl;
}