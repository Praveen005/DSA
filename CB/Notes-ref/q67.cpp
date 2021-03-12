#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isvalid(ll arr[], ll n, int k, ll ans) {
  ll currentsum = 0;
  ll painter = 1;
  for (ll i = 0; i < n; i++) {
    if (currentsum + arr[i] > ans) {

      ++painter;
      if (painter > k)
        return false;
      currentsum = arr[i];
    }
    else {
      currentsum += arr[i];
    }


  }
  return true;

}
ll binarysearch(ll arr[], ll n, ll k) {
  ll s = INT_MIN, e = 0, mid;
  // ll s , e , mid;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    s = max(s, arr[i]);
    e = e + arr[i];
  }
  while (s <= e) {
    mid = s + (e - s) / 2;
    if (isvalid(arr, n, k, mid)) {
      ans = mid;
      e = mid - 1;
    }
    else {
      s = mid + 1;
    }
  }
  return ans;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt" , "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll n, k, t;
  cin >> n >> k >> t ;
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << binarysearch(arr, n, k, t);
  // cout<<answer;
  return 0;
}