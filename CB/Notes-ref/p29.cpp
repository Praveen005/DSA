#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0; i<n; i++){
		cin>>a[i];

	}

	int cumsum[n]={0};
	int maxsum=0;
	cumsum[-1]=0;
	for(int i=0; i<n; i++){
		cumsum[i]=cumsum[i-1]+a[i];
	}


	for(int i=0; i<n;i++){
		int currentsum=0;
		for(int j=i; j<n; j++){
			currentsum=(cumsum[j]-cumsum[i-1]);
			if(maxsum<= currentsum){
				maxsum=currentsum;
			}
		}
	}
	cout<<endl<<" max sum of the subarray is "<<maxsum<<endl;
}