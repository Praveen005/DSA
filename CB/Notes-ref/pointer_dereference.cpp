#include<iostream>
using namespace std;
int main(){
	int x;
	x=10;
	int * xptr;
	xptr=&x;
	cout<<&x<<endl;
	cout<<xptr<<endl;

	cout<<*xptr<<endl;
	cout<<*(&x)<<endl;

	cout<<&xptr<<endl;

	cout<<&(*xptr)<<endl;
	//cout<<*(&xpt)
}