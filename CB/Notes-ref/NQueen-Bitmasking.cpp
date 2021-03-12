// N-Queen problem using BitMasking

//If you want to print the total number of such valid arrangement

#include<iostream>
using namespace std;
int n, DONE;
int ans = 0;
void place(int rowMask, int ld, int rd) {
	if (rowMask == DONE) {
		ans++;
		return;
	}
	int safe = DONE & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		safe = safe - p;
		place((rowMask | p), ((ld | p) << 1) , (rd | p) >> 1);
	}
}

int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	cin >> n;
	int rowMask = 0, ld = 0, rd = 0;
	DONE = (1 << n) - 1;
	place(rowMask, ld, rd);
	cout << ans << endl;

	

}

/*


//If you want to print the total number of such valid arrangement  as well as the arrangements



// N-Queen problem using BitMasking

#include<iostream>
using namespace std;
int n, DONE;
int ans = 0;
int status[100];
int count = 0;
void print(int status[], int count) {
	for (int i = 0; i < n; i++) {
		int num = status[i];
		int k = n;
		while (k > 0) {
			if (num & 1) {
				cout << "Q ";
			}
			else {
				cout << "_ ";
			}
			k--;
			num = num >> 1;
		}
		cout << endl;
	}
}
void place(int rowMask, int ld, int rd, int count) {
	if (rowMask == DONE) {
		print(status, count);
		cout << "\n\n";
		count = 0;
		ans++;

		return;
	}

	int safe = DONE & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		status[count] = p;

		safe = safe - p;
		place((rowMask | p), ((ld | p) << 1) , (rd | p) >> 1, count + 1);
	}
}

int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	cin >> n;
	int rowMask = 0, ld = 0, rd = 0;
	DONE = (1 << n) - 1;
	place(rowMask, ld, rd, count);
	cout << ans << endl;


}


*/
