#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[n];
	}
	sort(a, a+n);
	int target;
	cin>>target;
	int i=0;
	int j=n-1;
	while(i<j){
		j=n-1;
	int sum=a[i]+a[j];
	while(sum>=target){
		j--;
		sum=a[i]+a[j];
	}
	int k=i+1;

	while(k<j && k>i){
		for(int l=k; l<j;l++){
		
			
			if(a[i]+a[j]+a[l]==target){

		
				cout<<a[i]<<", "<<a[l]<<" and "<<a[j]<<endl<<endl;
				break;
			}
			
		}
	
		j--;
	}
	j=n-1;
	i++;
	
}
}