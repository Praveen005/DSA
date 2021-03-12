#include<iostream>
using namespace std;
int main(){
	int n,j;
	cin>>n; 
	int a[1000];
	int cumulative[1000]={0};
	cin>>a[0];
	cumulative[0]=a[0];
	
	for(int i=1;i<n;i++){
		cin>>a[i];
		cumulative[i]=cumulative[i-1]+a[i];
	}

	int left ,right;
	int maxsum=0;
	int currentsum;

	for(int i=0;i<n;i++){
		for( j=i;j<n;j++){
			currentsum=cumulative[j]-cumulative[i-1];  // whatif i=0 ? is cumulative[-1] legal?


			if(maxsum<=currentsum){
				maxsum=currentsum;
				left=i;
				right=j;
			}
		}
	}

	cout<<"max sum of a subarray is "<<maxsum<<" , and the subarray is "<<endl;
	for(int i =left; i<=right;i++){
		cout<<a[i]<<" ";
	}
}