#include<iostream>
using namespace std;
int kadanesAlgo(int *a  , int n){
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
	return max_sum ;
}


int main(){
	int testcase;
	cin>>testcase;
	while(testcase>0){
		int n;
		cin>>n;
		int a[n];
		int sum=0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			sum=sum+a[i];
		}
		int negativeA[n];
		for(int i=0; i<n; i++){
			negativeA[i]= -1*a[i];
		}
		int negSum= kadanesAlgo(negativeA ,n);
	//	int sum=kadanesAlgo(a,n);
		cout<<negSum+sum<<endl;
		testcase--;
	}
}