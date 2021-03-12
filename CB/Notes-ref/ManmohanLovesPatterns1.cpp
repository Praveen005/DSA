//  Manmohan Loves Patterns - I

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n<=1000 && n>=0){
		cout<<1<<endl;
		for(int i=2; i<=n; i++){
			int j=i;
			int k=i;
			if(j%2==0){
				cout<<1;
				while(j-2>0){
					cout<<0;
					j--;
				}
				cout<<1;
				cout<<endl;
			}
			else if(k%2 !=0){
				while(k>0){
					cout<<1;
					k--;
				}
				cout<<endl;
			}
		}
		break;
	}
}	

