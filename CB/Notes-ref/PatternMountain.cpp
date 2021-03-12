//pattern mountain

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int t=2*n-3;
	for(int i=1; i<=n; i++){
		int j=i,k=1;
		while(j>0){
			cout<<k<<"\t";
			k++;
			j--;
		}
		int m=t;
	
	
		while(m>0){
			cout<<" ";
			cout<<"\t";

			m=m-1;
		}

		if(i==n){
			k=k-2;
			j=j+2;
		}
		else{
			k=k-1;
			j=j+1;
		}
		
		while(j<=i){
			cout<<k;
			cout<<"\t";
			k--;
			j++;
		}
		cout<<endl;
		t=t-2;
	}

}