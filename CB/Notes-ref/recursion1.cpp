// decreasing sequence
// #include<iostream>
// using namespace std;
// void dec(int n) {
// 	if (n == 0) {
// 		return;
// 	}
// 	cout << n << " ";
// 	dec(n - 1);
// }
// int main() {
// 	int n = 10;
// 	dec(10);
// }


//increasing order

// #include<iostream>
// using namespace std;
// void dec(int n) {
// 	if (n == 0) {
// 		return;
// 	}
// 	// cout << n << " ";
// 	dec(n - 1);
// 	cout << n << " ";
// }
// int main() {
// 	int n = 10;
// 	dec(10);
// }


// check if array is sorted or not

#include<iostream>
using namespace std;
bool isSorted(int * a , int n) {
	if (n == 0 || n == 1) {
		return true;
	}
	if (a[0] <= a[1] && isSorted(a + 1, n - 1)) {
		return true;
	}
	return false;
}
int main() {
	int a[5] = { 1, 2, 3, 4, 5};
	if (isSorted(a, 5)) {
		cout << "yes sorted";
	}
	else {
		cout << " Not Sorted";
	}

}