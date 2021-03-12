#include<iostream>
using namespace std;
int main(){
	
	int n;
	cin>>n;
	int a[n]={0};

	for(int i=0; i<n ; i++){
		cin>>a[i];
	}
	int currentsum, maxsum=0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n;j++){
			currentsum=0;
			for(int k=i ;k<=j; k++){
				cout<<a[k]<<" ";
				currentsum=currentsum+a[k];
			}
			if(maxsum<=currentsum){
				maxsum=currentsum;
			}
			cout<<endl;
		}
	}

	cout<<endl<<"max sum of a sub array is "<<maxsum<<endl;
}