#include<iostream>
#include<list>
using namespace std;

// int search(int a[], int n, int key) {

// 	for (int i = 0; i < n; i++) {
// 		if (a[i] == key) {
// 			return i;
// 		}
// 	}
// 	return n;
// }



//now I want to make a generic function for linear search
// ForwardIterator is a container

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) {
	while (start != end) {
		if (*start == key) {
			return start;
		}
		start++;
	}
	return end;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	list<int>l;
	l.push_back(2);
	l.push_back(9);
	l.push_back(88);
	l.push_back(67);
	// int a[] = {1, 2, 7, 4, 5, 6, 8};
	// int n = sizeof(a) / sizeof(a[0]);
	int key = 2;
	list<int>::iterator it = search(l.begin(), l. end(), key);
	cout << *it << endl;

}