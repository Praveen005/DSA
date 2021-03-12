#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int i=0;
	while(i<n){
		cin>>a[i];
		i++;
	}
	int maxsum=0,currentsum, left,right,k;

	for(int i= 0 ; i<n   ; i++){

		for(int j= i ; j<n  ; j++){
			currentsum=0;

			for(k= i ; k<=j  ; k++){
				cout<<a[k]<<" ";
				currentsum=currentsum+a[k];
			}
			cout<<endl;
			if(maxsum<=currentsum){
				maxsum=currentsum;
				left=i;
				right=k-1;
			}
		}
	}
	cout<<"max sum of a sub array is "<<maxsum<<endl<<"left = "<<left<<endl<<"right = "<<right<<endl;

	 for(int m=left; m<=right;m++){
	 	cout<<a[m];
	 }
}