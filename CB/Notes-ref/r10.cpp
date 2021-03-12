#include <stdio.h>
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char str[200];
	scanf("%[^\n]%*c", str);
	int i = 0;
	char ch;
	//
	ch = getchar();
	char str1[200];
	int j = 0;
	while (str[i] != '\0') {
		if (str[i] != ch) {
			str1[j] = str[i];
			j++;
		}
		i++;
	}
	str1[j] = '\0';
	printf("%s", str1);
	return 0;
}