// // Broken calculator
// // this program will calculate the factorial of large numbers
// #include<iostream>
// using namespace std;
// #define M 10000
// int multiply(int * f, int f_size, int p) {
// 	int carry = 0;
// 	for (int i = 0; i < f_size; i++) {
// 		int k = (p * f[i] + carry);
// 		f[i] = k % 10;
// 		carry = k / 10;
// 	}
// 	while (carry) {
// 		f[f_size] = carry % 10;
// 		f_size++;
// 		carry = carry / 10;
// 	}
// 	return f_size;
// }
// void factorial(int n) {
// 	int f[M];
// 	f[0] = 1;
// 	int f_size = 1;
// 	for (int i = 2; i <= n; i++) {
// 		f_size = multiply(f, f_size, i);
// 	}
// 	for (int i = f_size - 1 ; i >= 0; i--) {
// 		cout << f[i];
// 	}
// 	cout << endl;// << f_size << endl;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n;
// 	cin >> n;
// 	factorial(n);

// }




// string tokenizer
// #include<iostream>
// #include<cstring>
// using namespace std;

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[] = "today is a rainy day";
// 	auto ptr = strtok(ch, " ");
// 	cout << ptr << endl;
// 	while (ptr != NULL) {
// 		ptr = strtok(NULL, " ");
// 		cout << ptr << endl;
// 	}
// }

// my string tokenizer
// #include<iostream>
// #include<cstring>
// using namespace std;
// char* mystrtok(char * ch , char delim) {
// 	static char* input = NULL;
// 	if (ch != NULL) {
// 		input = ch;
// 	}
// 	if (input == NULL) {
// 		return NULL;
// 	}
// 	char* output = new char[strlen(input) + 1];
// 	int i = 0;
// 	while (input[i] != '\0') {
// 		if (input[i] != delim) {
// 			output[i] = input[i];
// 		}
// 		else {
// 			output[i] = '\0';
// 			input += i + 1;
// 			return output;
// 		}
// 		i++;
// 	}
// 	output[i] = '\0';
// 	input = NULL;
// 	return output;
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[] = "today is a rainy day";
// 	char* ptr = mystrtok(ch, ' ');
// 	cout << ptr << endl;
// 	while (ptr != NULL) {
// 		ptr = mystrtok(NULL, ' ');
// 		cout << ptr << endl;
// 	}
// }   // done and dusted





// //string tokenizer
// #include<iostream>
// #include<cstring>
// using namespace std;

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	char ch[] = "abcd";
// 	cout << strlen(ch) << endl;
// 	cout << sizeof(ch) << endl;

// }

// //sorting a list of strings
// #include<iostream>
// //#include<string>
// #include<algorithm>
// //#include<cstring>
// using namespace std;

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	string s[10];
// 	int n; cin >> n; cin.get();
// 	for (int i = 0; i < n; i++) {
// 		getline(cin, s[i]);
// 	}
// 	sort(s, s + n);
// 	for (int i = 0; i < n; i++) {
// 		cout << s[i] << endl;
// 	}
// }


// //insertion sort
// #include<iostream>
// #include<cstring>
// using namespace std;
// void insertionSort(int *a, int n) {
// 	for (int i = 1; i < n; i++) {
// 		int e = a[i];
// 		int j = i - 1;
// 		while (a[j] > e && j >= 0) {
// 			a[j + 1] = a[j];
// 			j--;
// 		}
// 		a[j + 1] = e;
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;
// 	int a[1000];
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	insertionSort(a, n);
// 	for (int i = 0; i < n; i++) {
// 		cout << a[i] << " ";
// 	}

// }


