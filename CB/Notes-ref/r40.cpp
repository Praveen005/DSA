#include<iostream>
using namespace std;
int gcd(int n1, int n2) {
	if (n2 == 0) {
		//cout<<n1<<endl;
		return n1;
	}
	return gcd(n2, n1 % n2);
}
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int hcf = gcd(n1, n2);

	cout << (n1 * n2) / hcf << endl;
	return 0;
}