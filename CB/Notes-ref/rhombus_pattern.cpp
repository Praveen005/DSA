#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n>0 && n<=20){
		int l=n;
		int k=n-1;
		while(k>0){
			cout<<" ";
			k--;
		}
		
		while(l>0){
			cout<<"*";
			l--;
		}
		cout<<endl;
		int k2=n-2;
		while(k2>0){
			int k3=k2,k1=n-2;
			while(k3>0){
				cout<<" ";
				k3--;
			}
			cout<<"*";
			while(k1>0){
				cout<<" ";
				k1--;
			}
			cout<<"*"<<endl;
			k2--;
		}
		while(n>0){
			cout<<"*";
			n--;
		}
		break;
	}
}