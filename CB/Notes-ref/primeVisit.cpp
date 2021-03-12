//prime seive
#include<iostream>

using namespace std;
#define ll long long
void prime_seive(int a[]) {
	//only multiples of of 3 can be prime
	for (int i = 3; i <= 100000; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3 ; i <= 1000000; i += 2) {
		//sabse bada sawal ye tha ki jab upar hum ne saare odd ko mark kar rakha hai
		//to phir se check karne ki kya jarurat hai niche waala if condition laga kar ?
		// wo iss liye jaruri hai kyun ki jab aap i=3 lete ho to already 15  mark ho jata hai 0.
		//agar if niche nahi lagate ho then phir se 15 le kar mark kar rahe ho aap
		//matlab repetition ho raha.
		//aisa kewal 15 nahi, bahot saare number honge kyun range bada hai
		//and wo phir TLE de dega :)
		//issiliye use karen ye if() condition
		if (a[i] == 1) {

			for (ll j = i * i;  j <= 1000000; j += i ) {
				a[j] = 0;

			}
		}
	}
	a[2] = 1;
	a[0] = a[1] = 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[1000000] = {0};


	prime_seive(a);
	int itr;
	cin >> itr;
	while (itr > 0) {
		int n1, n2;
		cin >> n1 >> n2;
		int count = 0;
		for (int i = n1; i <= n2; i++) {
			if (a[i] == 1) {
				//	cout<<i<<"  ";
				count++;
			}
		}
		cout << count << endl;
		itr--;
	}

}