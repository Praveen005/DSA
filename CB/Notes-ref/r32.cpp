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

929394959493929
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
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      ind[i] = 1;
      s[i] = s[n - 1 - i] = max(s[i], s[n - 1 - i]);
      cnt--;
    }
  }
  cout << cnt << endl;
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