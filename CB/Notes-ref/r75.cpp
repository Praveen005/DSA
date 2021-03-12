// #include<iostream>
// #include<cmath>
// using namespace std;
// #define int long long
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;

// 		int i;
// 		for ( i = 0; i < n; i++) {
// 			int k;
// 			cin >> k;
// 			if (k < 0 || k > 1000000000) {
// 				cout << "No" << endl;
// 				// flag = true;
// 				break;
// 			}
// 		}
// 		if (i == n) {
// 			cout << "Yes" << endl;
// 		}
// 	}


// }



// #include<iostream>
// #include<cmath>
// using namespace std;
// #define int long long
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;
// 		int k;
// 		int i;
// 		for ( i = 0; i < n; i++) {
// 			cin >> k;
// 			if (k < 0 || k > 1000000000) {
// 				cout << "No" << endl;
// 				break;
// 			}
// 		}
// 		if (i == n) {
// 			cout << "Yes" << endl;
// 		}

// 	}
// }


// #include<iostream>
// using namespace std;
// int count = 0;
// void func(int n, char* out, int i) {
// 	if (i >= n) {
// 		count++;
// 	}
// 	out[i] = 'a';
// 	func(n, out, i + 1);
// 	out[i] = 'b';
// 	func(n, out, i + 2);
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;
// 		char out[50];
// 		count = 0;
// 		func(n, out, 0);
// 		cout << count << endl;
// 	}
// 	return 0;
// }


// #include<iostream>
// using namespace std;
// int count = 0;
// void func(int n, int i) {
// 	if (i >= n) {
// 		count++;
// 		return;
// 	}

// 	func(n,  i + 1);

// 	func(n,  i + 2);
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	int k = 1;
// 	while (t--) {
// 		int n; cin >> n;

// 		count = 0;
// 		func(n,  0);
// 		cout << "#" << k << " : ";
// 		cout << count << endl;
// 		k++;
// 	}
// 	return 0;
// }





// #include<iostream>
// #include<cstring>
// using namespace std;
// void move(char*ch, int i, int j) {
// 	if (i >= j) {
// 		return ;
// 	}
// 	if (i == strlen(ch) - 1) {
// 		move(ch, 0, j - 1);
// 	}
// 	if (ch[i] == 'x') {
// 		swap(ch[i], ch[i + 1]);
// 		move(ch, i + 1, j);
// 	}
// 	move(ch, i + 1, j);

// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[1005];
// 	cin >> ch;
// 	int n = strlen(ch);
// 	move(ch, 0, n - 1);
// 	cout << ch << endl;
// }



// #include<iostream>
// #include<cstring>
// using namespace std;
// void(replacePI(char*ch, int i, int n)) {
// 	if (ch[i] == '\0') {
// 		return;
// 	}
// 	if (ch[i] == 'p' and ch[i + 1] == 'i') {
// 		for (int k = n - 1; k >= i + 2; k--) {
// 			ch[k + 2] = ch[k ];
// 		}
// 		ch[n + 2] = '\0';
// 		ch[i] = '3';
// 		ch[i + 1] = '.';
// 		ch[i + 2] = '1';
// 		ch[i + 3] = '4';
// 		replacePI(ch, i + 4, n + 2);
// 	}
// 	replacePI(ch, i + 1, n);
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	while (t--) {
// 		char ch[10005];
// 		cin >> ch;
// 		replacePI(ch, 0, strlen(ch));
// 		cout << ch << endl;
// 	}
// 	return 0;
// }




// #include<iostream>
// using namespace std;
// void merge(int*input, int s, int e) {
// 	int mid = (s + e) / 2;
// 	int i = s;
// 	int j = mid + 1;
// 	int output[200005];
// 	int count = s;
// 	while (i <= mid  and j <= e) {
// 		if (input[i] <= input[j]) {
// 			output[count++] = input[i++];
// 		}
// 		else {
// 			output[count++] = input[j++];
// 		}
// 	}
// 	while (i <= mid) {
// 		output[count++] = input[i++];
// 	}
// 	while (j <= e) {
// 		output[count++] = input[j++];
// 	}

// 	for (int i = s; i <= e; i++) {
// 		input[i] = output[i];
// 	}
// }
// void QuickSort(int *input, int i, int j) {
// 	if (i >= j) {
// 		return;
// 	}
// 	int mid = (i + j) / 2;
// 	QuickSort(input, i, mid);
// 	QuickSort(input, mid + 1, j);
// 	merge(input, i, j);
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;
// 	int input[200005];
// 	for (int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}
// 	QuickSort(input, 0, n - 1);
// 	for (int i = 0; i < n; i++) {
// 		cout << input[i] << " ";
// 	}
// 	return 0;
// }




//TOWER OF HANOI

// #include<iostream>
// using namespace std;
// void hanoi(int n, char source, char helper, char destination) {
// 	if (n <= 0) {
// 		return;
// 	}
// 	hanoi(n - 1, source, destination, helper);
// 	cout << "Moving ring " << n << " from " << source << " to " << destination << endl;
// 	hanoi(n - 1, helper, source, destination);
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int n; cin >> n;
// 	hanoi(n, 'A', 'C', 'B');
// }






//	QUICKSORT
// #include<iostream>
// using namespace std;
// int func(int input[], int s, int e) {
// 	int pivot = input[e];
// 	int i = s - 1;

// 	int k = s;
// 	for (; k < e; k++) {
// 		if (input[k] <= pivot) {
// 			swap(input[i + 1], input[k]);
// 			i++;

// 		}
// 	}
// 	swap(input[i + 1], input[e]);

// 	return i + 1;
// }
// void QuickSort(int *input, int i, int j) {
// 	if (i >= j) {
// 		return;
// 	}
// 	int pivot = func(input, i, j);
// 	QuickSort(input, i, pivot - 1);
// 	QuickSort(input, pivot + 1, j);
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;
// 	int input[200005];
// 	for (int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}
// 	QuickSort(input, -1, n - 1);
// 	for (int i = 0; i < n; i++) {
// 		cout << input[i] << " ";
// 	}
// 	return 0;
// }






// #include<iostream>
// #include<cstring>
// using namespace std;
// #define int long long
// int s2I(char* ch, int n) {
// 	if (n == 0) {
// 		return 0;
// 	}
// 	int digit = ch[n - 1] - '0';
// 	int ans = s2I(ch, n - 1);
// 	return ans * 10ll + digit;
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[15];
// 	cin >> ch;
// 	cout << s2I(ch, strlen(ch));
// 	return 0;
// }




// #include<iostream>
// #include<cstring>
// using namespace std;
// #define int long long
// bool subsetSumZero(int*a, int n, int i, int sum) {
// 	if (i == n) {
// 		return false;
// 	}

// 	sum += a[i];
// 	if (sum == 0) {
// 		return true;
// 	}
// 	if (subsetSumZero(a, n, i + 1, sum)) {
// 		return true;
// 	}
// 	sum -= a[i];
// 	if (subsetSumZero(a, n, i + 1, sum)) {
// 		return true;
// 	}


// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;
// 		int a[10];
// 		for (int i = 0; i < n; i++) {
// 			cin >> a[i];
// 		}
// 		bool ans = subsetSumZero(a, n, 0, 0);
// 		if (!ans) {
// 			cout << "No" << endl;
// 		}
// 		else {
// 			cout << "Yes" << endl;
// 		}
// 	}
// }

// #include<iostream>
// #include<cstring>
// #include<set>
// using namespace std;
// set<string>s;
// string chr;
// void permute(char*ch, int i) {
// 	if (ch[i] == '\0') {
// 		string ss = ch;
// 		if (ss > chr)
// 			s.insert(ss);

// 		return;
// 	}

// 	for (int k = i; ch[k] != '\0'; k++) {
// 		swap(ch[i], ch[k]);
// 		permute(ch, i + 1);
// 		swap(ch[i], ch[k]);
// 	}
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[30];
// 	cin >> ch;
// 	chr = ch;
// 	char out[25];
// 	permute(ch, 0);
// 	for (auto x : s) {
// 		cout << x << endl;
// 	}
// }




// #include<iostream>
// #include<cstring>
// #include<set>
// using namespace std;
// // string searchIn [] = {
// // 	"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
// // 	"utkarsh", "divyam", "vidhi", "sparsh", "akku"
// // };

// char digit[][25] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


// int l = 0;
// void key(char* in, char out[][100], int i, int j) {
// 	if (in[i] == '\0') {
// 		// out[l][j] = '\0';
// 		// cout << out[l] << endl;
// 		// // cout << out[l][0] << " " << out[l][1] << " ";
// 		// l++;
// 		// // l = 0;
// 		// // vi = j;
// 		return;
// 	}
// 	int no = in[i] - '0';
// 	for (int k = 0; digit[no][k] != '\0'; k++) {
// 		char chr = digit[no][k];
// 		// cout << k << "  ";
// 		// cout << chr << "  ";
// 		out[l][j] = chr;
// 		key(in, out, i + 1, j + 1);
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char in[15];
// 	cin >> in;
// 	char ch[10000][100];
// 	key(in, ch, 0, 0);


// }




// #include<iostream>
// #include<cstring>
// #include<set>
// #include<string>
// using namespace std;

// char digit[][25] = {"", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};



// void key(char* in, char out[], int i, int j) {
// 	if (in[i] == '\0') {
// 		out[j] = '\0';
// 		cout << out << endl;
// 		return;
// 	}
// 	int no = in[i] - '0';
// 	if (no == 0) {
// 		out[j] = ' ';
// 		key(in, out, i + 1, j + 1);
// 	}
// 	for (int k = 0; digit[no][k] != '\0'; k++) {
// 		char chr = digit[no][k];
// 		out[j] = chr;
// 		key(in, out, i + 1, j + 1);
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char in[15];
// 	cin >> in;
// 	char out[100];
// 	key(in, out, 0, 0);

// }
/*
26
2396 25316 30085 23080 10269 5711 8306 11536 19092 6816 6305 23649 32583 5585
14193 14859 30265 18026 5528 16126 15212 25591 14789 3900 31395 25529

224098
*/




#include<iostream>
using namespace std;

// int sum = 0;

int solve(int a[], int i, int j) {
	if (i > j) {
		return 0;
	}
	int sum1 = a[i] + min(solve(a, i + 1, j - 1), solve(a, i + 2, j));
	int sum2 = a[j] + min(solve(a, i, j - 2), solve(a, i + 1, j - 1));
	return max(sum1, sum2);



}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a[40];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solve(a, 0, n - 1);
	// cout << sum << endl;
	return 0;
}





// #include<iostream>
// using namespace std;
// #define int long long

// int sum = 0;

// void solve(int a[], int n, int i, int j, int sum1) {
// 	if (n == 0) {


// 		sum = max(sum, sum1);

// 		return;
// 	}

// 	if ((n & 1) == 0) {
// 		sum1 += a[i];
// 		solve(a, n - 1, i + 1, j, sum1);
// 		sum1 -= a[i];
// 		sum1 += a[j];
// 		solve(a, n - 1, i, j - 1, sum1);




// 	}
// 	else {
// 		//if (a[i] > a[j]) {

// 		solve(a, n - 1, i + 1, j, sum1);
// 		//	}
// 		//	else {

// 		solve(a, n - 1, i, j - 1, sum1);
// 		//	}
// 	}
// }
// int main() {

// 	int n; cin >> n;
// 	int a[40];
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	solve(a, n, 0, n - 1, 0);
// 	cout << sum << endl;
// 	return 0;
// }