// WAP to count the number of occurrences of vowels in a string
#include<iostream>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char ch[] = "PRAVEENmishra" ;
	int i = 0;
	int count = 0;
	for (;  i < (sizeof(ch) - 1) ;  i++) {
		if (ch[i] == 'a' || ch[i] == 'e'
		        || ch[i] == 'i' || ch[i] == 'o'
		        || ch[i] == 'u' || ch[i] == 'A'
		        || ch[i] == 'E' || ch[i] == 'I'
		        || ch[i] == 'O' || ch[i] == 'U')  {
			count++;
		}
	}
	printf("%d", count);


}
