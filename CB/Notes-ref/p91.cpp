//rainwater harvesting
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[n];
	}
	int left[n];
	int right[n];
	left[0]=0;
	right[n-1]=0;
	for(int i=1; i<n; i++){
		left[i]=max(left[i-1] , a[i]);

	}

	for(int i=n-2; i>=0; i--){
		right[i]=max(right[i+1] , a[i+1]);
		
	}
	int storage=0;
	for(int i=0; i<n; i++){
		if(left[i]>a[i] && right[i]>a[i]){
			storage = storage+ (min(right[i] , left[i])-a[i]);
		}
	}

	cout<<storage<<endl;


}