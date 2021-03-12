// // WAP using pointer to reverse an array
// #include<iostream>
// using namespace std;
// void swap(int *a, int *b) {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
// void reverse(int*a, int n) {
// 	int * s = a;
// 	int * e = a + n;
// 	int i = 1;
// 	for (int i = 0; i <= n / 2; i++) {
// 		swap((a + i), (a + n - 1 - i));
// 	}
// 	for (int i = 0; i < n; i++) {
// 		printf("%d ", *(a + i));
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;
// 	int a[n];
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d", &a[i]);
// 	}
// // printing the original array
// 	for (int *i = a; i < a + n; i++) {
// 		printf("%d ", *i);
// 	}
// 	printf("\n");

// 	reverse(a, n);
// }


// WAP using pointer to reverse an array
// #include<stdio.h>
// void swap(int *a, int *b) {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
// void reverse(int*a, int n) {
// 	int * s = a;
// 	int * e = a + n;
// 	int i = 1;
// 	for (int i = 0; i <= n / 2; i++) {
// 		swap((a + i), (a + n - 1 - i));
// 	}
// 	for (int i = 0; i < n; i++) {
// 		printf("%d ", *(a + i));
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; //cin >> n;
// 	scanf("%d", &n);
// 	int a[n];
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d", &a[i]);
// 	}
// // printing the original array
// 	for (int *i = a; i < a + n; i++) {
// 		printf("%d ", *i);
// 	}
// 	printf("\n");

// 	reverse(a, n);
// }


// /*
// Q2. WAP using pointer to merge two arrays such that array elements in the
// resulting array are in ascending order. Initially the two arrays are in
// random order.
// */
// #include<iostream>
// using namespace std;
// void sort(int *c , int n) {
// 	for (int iteration = 0; iteration < n - 1; iteration++) {

// 		int min_index = iteration;

// 		for (int i = iteration + 1; i < n; i++) {
// 			if (c[i] < c[min_index]) {
// 				min_index = i;

// 			}
// 		}

// 		swap(c[min_index], c[iteration]);
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a[] = {13, 4 , 5, 77, 2, 11};
// 	int b[] = {3, 7, 1, 33, 45};
// 	int n = sizeof(a) / sizeof(a[0]);
// 	int m = sizeof(b) / sizeof(b[0]);
// 	// declared another array to store the merged array
// 	int c[m + n];
// 	for (int i = 0; i < m + n; i++) {
// 		if (i < n) {
// 			*(c + i) = *(a + i);
// 		}
// 		else {
// 			*(c + i) = *(b + i - n);
// 		}
// 	}
// 	sort(c, m + n);
// 	for (int i = 0; i < m + n; i++) {
// 		printf("%d ", *(c + i));
// 	}

// }



/*
Q2. WAP using pointer to merge two arrays such that array elements in the
resulting array are in ascending order. Initially the two arrays are in
random order.
*/
// #include<stdio.h>
// void swap(int *a, int *b) {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
// void sort(int *c , int n) {
// 	for (int iteration = 0; iteration < n - 1; iteration++) {

// 		int min_index = iteration;

// 		for (int i = iteration + 1; i < n; i++) {
// 			if (*(c + i) < * (c + min_index)) {
// 				min_index = i;
// 			}
// 		}
// 		swap((c + min_index), (c + iteration));
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a[] = {13, 4 , -5, 77, 2, 11};
// 	int b[] = {3, 7, 1, 33, 45};
// 	int n = sizeof(a) / sizeof(a[0]);
// 	int m = sizeof(b) / sizeof(b[0]);
// 	// declared another array to store the merged array
// 	int c[m + n];
// 	for (int i = 0; i < m + n; i++) {
// 		if (i < n) {
// 			*(c + i) = *(a + i);
// 		}
// 		else {
// 			*(c + i) = *(b + i - n);
// 		}
// 	}
// 	sort(c, m + n);
// 	for (int i = 0; i < m + n; i++) {
// 		printf("%d ", *(c + i));
// 	}

// }


// Q3. WAP to find the maximum number in an array using pointers.
// #include<iostream>
// using namespace std;
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int a[] = {1, 2, 3, 4, 5, 77, 44, 78, 22, -22, 123};
// 	int n = sizeof(a) / sizeof(a[0]);
// 	int max = *a;
// 	for (int i = 0; i < n; i++) {
// 		if (*(a + i) > max) {
// 			max = *(a + i);
// 		}
// 	}
// 	cout << max << endl;

// }



// #include<stdio.h>
// int main() {
// 	int a[] = {1, 2, 3, 4, 5, 77, 44, 78, 224, -22, 123};
// 	int n = sizeof(a) / sizeof(a[0]);
// 	int max = *a;
// 	for (int i = 0; i < n; i++) {
// 		if (*(a + i) > max) {
// 			max = *(a + i);
// 		}
// 	}
// 	printf("%d\n", max);
// }


/*
Q3. WAP to compare two strings using pointers. (do not use strcmp())

(check whether the two strings are equal)
*/

// #include<iostream>
// using namespace std;
// // int stringComp(char* ch, char*a) {

// // }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	char ch[] = "ram";
// 	char a[] = "ram";
// 	// if (stringComp(ch, a)) {
// 	// 	printf("Strings are equal");
// 	// }
// 	// else
// 	// 	printf("Strings are unequal");
// 	// return 0;


// }


// Q4.  WAP to compare two strings using pointers. (do not use strcmp())

//      (check whether the two strings are equal)
#include<stdio.h>
#include<string.h>
int stringComp(char* ch, char*a) {
	int n = strlen(ch);
	if (strlen(ch) == strlen(a)) {
		for (int i = 0; i < n; i++) {
			// using pointers to compare here
			if (*(ch + i) != *(a + i)) {
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{

	char ch[] = "Tezpur";
	char a[] = "Tezpur";
	if (stringComp(ch, a)) {
		printf("Strings are equal");
	}
	else
		printf("Strings are unequal");
	return 0;
}



