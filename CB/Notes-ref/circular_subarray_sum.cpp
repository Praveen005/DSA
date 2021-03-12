#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100];
	int cum[100];
	cum[-1]=0;
	for(int i=0; i<n; i++){
		cin>>a[i];
		cum[i]=cum[i-1]+a[i];
	}
	int candidate1=cum[n-1];
	int b[100];
	int cs=0, ms=0;
	for(int i=0; i<n; i++){
		b[i]= -1*a[i];

		cs=cs+b[i];
		if(cs<0){
			cs=0;
		}

		if(ms<=cs){
			ms=cs;
		}
	}

	int candidate2=ms;
	cout<<max(candidate1,(candidate1+candidate2))<<endl;

}