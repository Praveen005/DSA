// 2) WAP to take a string as user input and then reverse the string.
#include<stdio.h>

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	char ch[20000];
	scanf("%[^\n]%*c", ch);

	int i = 0;
	while (ch[i] != '\0') {
		i++;
	}

	int c;
	for (c = i - 1; c >= 0; c--) {
		printf("%c", ch[c]);
	}
}
