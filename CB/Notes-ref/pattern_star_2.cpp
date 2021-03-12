#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1 ; i<=n; i++){
		int k1=i,k2=1,k3=n-i;
		while(k1>0){
			cout<<k2;
			k2++;
			k1--;
		}
		while(k3>0){
			cout<<"*";
			k3--;
		}
		cout<<endl;
	}
}