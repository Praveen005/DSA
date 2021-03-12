#include<iostream>
using namespace std;
void kadanesAlgo(int *a  , int n){
	int current_sum=0;
	int max_sum=0;
	for(int i=0 ; i<n; i++){
		current_sum=current_sum+a[i];
		if(current_sum<0){
			current_sum=0;
		}
		if(max_sum<current_sum){
			max_sum=current_sum;
		}
	}
	cout<<max_sum<<endl;
}


int main(){
	int testcase;
	cin>>testcase;
	while(testcase>0){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		testcase--;
		kadanesAlgo(a,n);
	}
}