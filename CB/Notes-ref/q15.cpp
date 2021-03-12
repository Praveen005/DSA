#include<iostream>
using namespace std;
int numberExtracter(char * carr, int m) {
	int num = 0;
	int factor = 1;
	for (int i = m - 1; i >= 0; i--) {
		num += ((carr[i] - '0') * factor);
		factor *= 10;

	}
//	cout << num << endl;
	return num;
}


void cBnumber(char *ch, int n) {

	char c[n];
	bool flag1, flag2;
	int count = 0;
	int cBnumber[100];
	int b[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int m = 0;
			//	num = 0;
			for (int k = i; k <= j; k++) {
				c[m] = ch[k];

				m++;


			}

			int number = numberExtracter(c, m);
			int i;
			for ( i = 0; i < 10; i++) {
				if (number == 0 || number == 1) {
					break;
				}
				if (number == b[i]) {
					cBnumber[count] = number;
					//	cout << number << endl;
					count++;
					bool flag1 = true;
					break;
				}
				else {
					flag1 = false;
				}

				if (number % b[i] == 0) {
					break;
				}
			}
			if (i == 10) {
				cBnumber[count] = number;
				//	cout << number << endl;
				count++;
				bool flag2 = true;
			}
			else {


				flag2 = false;
			}

		}
		if (flag1 == true  || flag2 == true) {
			break;
		}
	}
	for (int i = 0; i < count; i++) {
		cout << cBnumber[i] << " ";
	}
	int count1 = count;
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if ((cBnumber[i] - cBnumber[j]) % 10 == 0) {
				count1--;
			}
		}
	}

	cout << count1 << endl;

	//cout << endl << count << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	char ch[100];
	for (int i = 0; i < n; i++) {
		cin >> ch[i];
	}
	cBnumber(ch, n);
}