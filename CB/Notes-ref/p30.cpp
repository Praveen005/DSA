// kadane's algorithm to find max sum sub-array
#include<iostream>
using namespace std;
 int main(){
 	int n;
 	cin>>n;
 	int a[n]={0};
 	for(int i=0; i<n; i++){
 		cin>>a[i];
 	}
 	int maxsum=0, currentsum=0;
 	for(int i=0; i<n; i++){
 		currentsum=currentsum+a[i];
 		if(currentsum<0){
 			currentsum=0;
 		}
 		if(maxsum<=currentsum){
 			maxsum=currentsum;
 		}
 	}
 	cout<<"max sum of the sub-array is "<<maxsum<<endl;
 }