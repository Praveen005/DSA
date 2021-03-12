#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;

	int array[n];
	for(int i=0; i<n; i++){
		cin>>array[i];
	}
	int array1[n];
	for(int i=0; i<n; i++){
		array1[i]=-1*array[i];
	}
	int sum=0, cursum=0, maxsum=0;
	//now we will apply kadane's algorithm on array1
	for(int i=0; i<n; i++){
		sum=sum+(array[i]);
		cursum=cursum+array1[i];
		if(cursum<0){
			cursum=0;
		}
		if(maxsum<=cursum){
			maxsum=cursum;
		}
	}

	cout<<"max circular subarray sum= "<<sum+maxsum;


}