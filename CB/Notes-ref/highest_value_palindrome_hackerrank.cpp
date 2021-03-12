/*
s: a string representation of an integer
  n: an integer that represents the length of the integer string
k: an integer that represents the maximum number of changes allowed

Sample Input 0
4 1
3943
Sample Output 0
3993

Sample Input 1
6 3
092282
Sample Output 1
992299


Sample Input 2
4 1
0011
Sample Output 2
-1

15 8
128392759430124
Output:
929394959493929

5 1
12121
output:
12921
*/
#include<iostream>
#include<cstring>
using namespace std;
#define e (n-1-i)
const int N = 100005;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k;  cin >> n >> k;
  char s[N];
  int ind[N] = {0};
  cin >> s;
  int cnt = k;
  /*
  * mere paas total changes k hain.
  *mai sabse pahle string bana leta hun.
  set them to the max of the two value(palindrome pair)
  *ab agr string banane me jitne changes the agar usse jyada kharch kar diye,
  matlab utne changes me string banana possible nahi hai.
  and so print -1.
  * if not , then now we have to maximize the string value.
  *to maximize, most significant waale se change karenge.
  *so, the max that we can replace a digit with is '9'
  *suppose one of pair was(1,4) then in 1st step we changed it to (4,4).
  here 1 change has been utilised . suppose we change (1,4) to (9,9) : 2 changes needed
  , 1 utilized during (1,4) to (4,4);
  so in next step we will reduce count by only one in (4,4) to (9,9) because 1 has already been
  utilized in (1,4) to (4,4)
  * what does ind[]  represent ?  : it represents if in original string the pair is different or not.
  if pair is(2,2) then leave is at it is because it is already initialized to 0.

  * this condition :  else if (s[i] != '9' && ind[i] == 0 && cnt >= 2)
  means in original string two elements of the pair are not 9 and but sth like (3,3)
  cnt>=2  to eliminate this case from entering inside : 5 1 12121
  * last if()  condition is for middle element of the odd length array.




  */
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      ind[i] = 1;
      s[i] = s[n - 1 - i] = max(s[i], s[n - 1 - i]);
      cnt--;
    }
  }

  if (cnt < 0) {
    cout << -1 << endl;
  }

  else {

    for (int i = 0; i < n / 2 && cnt > 0; i++) {
      if (s[i] != '9' && ind[i] == 1) {
        s[i] = '9';
        s[n - 1 - i] = '9' ;
        cnt--;
      }
      else if (s[i] != '9' && ind[i] == 0 && cnt >= 2) {
        s[i] = '9';
        s[n - 1 - i] = '9' ;
        cnt -= 2;
      }
    }


    if (n % 2 == 1 && cnt > 0) {
      s[n / 2] = '9';
    }
    cout << s << endl;
  }
}