// Q3. WAP to concatenate to strings without using strcat().
#include<iostream>
using namespace std;
void concatenate(char a[], char b[]) {
	static int j = 0;
	int i = 0;
	while (a[i] != '\0') {
		b[j] = a[i];
		i++;
		j++;
		//cout << i << " ";
	}
	b[j] = '\0';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[100];
	char b[100];
	// n is the number of strings you want to add/concatenate
	int n; cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", a);

		concatenate(a, b);
	}
	printf("%s\n", b);


}
