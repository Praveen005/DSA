




//this is not a pascal triangle




#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int l=n-1;
	
	//int d=n-2;

	
	for(int i=1; i<n; i++){
		int k=l;
		while(k>0){
			cout<<" ";
			k--;
		}
		l--;
		if(i==1){
			cout<<1<<" ";
			cout<<endl;
			continue;

		}
		
		cout<<1<<" ";

		int j=i-1;
		int m=i-2;
		while(m>0){
			cout<<j<<" ";
			m--;
		}
	//	d--;
		cout<<1<<" ";
		cout<<endl;

	}
}