#include <stdio.h>
int check(char str[], char str1[], int i, int l) {
	int j = 0;
	int p;
	for (p = i; p < i + l; p++) {
		if (str[p] != str1[j]) {
			return 0;
		}
		j++;
	}
	if ((str[p] >= 'a' && str[p] <= 'z') || (str[p] >= 'A' && str[p] <= 'Z'))
		return 0;
	else {
		return 1;
	}
}
// The man we saw saw a saw.
// saw
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//str will strore the text: be it sentence or passage whithout new line chracter
	char str[200];
	scanf("%[^\n]%*c", str);
	//str1 will strore the word whose occurances is to be searched for.
	char str1[200];
	scanf("%[^\n]%*c", str1);
	int l = 0;
	while (str1[l] != '\0') {
		l++;
	}
	int m = 0;
	int flag = 0;
	while (str[m] != '\0') {
		m++;
	}
	// 'ar' is the array in which we will strore the text without those particular words
	char ar[200];
	int i, j; int  q = 0, cnt = 0;
	for (i = 0; i < m; i++) {

		if (str[i] == str1[0]) {
			if (check(str, str1, i, l)) {
				flag = 1;
				q = i;
			}

		}
		if (flag == 1 && i < q + l) {
			continue;
		}
		else {
			flag = 0;
			ar[cnt] = str[i];
			cnt++;
		}
		ar[cnt] = '\0';
	}

	printf("%s\n", ar);

}