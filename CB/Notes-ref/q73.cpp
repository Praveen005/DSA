#include<iostream>
#include<algorithm>
using namespace std;
bool

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt" , "r" , stdin);
  freopen("output.txt" , "w" , stdout);
#endif
  int n; cin >> n;
  string s[1005];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);

  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}