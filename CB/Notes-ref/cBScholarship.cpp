//CB SCHOLARSHIP
//we have to maximize the number of students gettting the scholarship
//'ll try using B-S'
//kya aapko monotonic search space dikh raha hai?   :)

#include<iostream>
using namespace std;
#define ll long long
bool schecker(int no_of_students , int discount_coupons, int x, int y , ll n) {
	/*mid means check karna hai ki mid no of students ko
	100% scholarship de sakte hain yan nahi.
	here we are given with a mid value from below BS to check if this mush discount
	coupons can be given or not.
	this will decide our future course of action.
	agar de paye to try karenge ki aur logon ko mil jaaye
	bcz we have to maximize the number of students getting scholarship.
	if not then reduce kar denge
	*/

	ll z = (n * x);
	ll z1 = (discount_coupons + ((no_of_students - n) * y));
	if (z <= z1) {
		return true;
	}
	else return false;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int no_of_students;
	int discount_coupons;
	int x;
	int y;
	int ans = 0;
	cin >> no_of_students >> discount_coupons >> x >> y;
	int s = 0;
	int e = no_of_students;
	while (s <= e) {
		ll mid = (s + e) / 2;
		bool sahiHai = schecker( no_of_students , discount_coupons, x, y, mid);
		if (sahiHai) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << endl;

}