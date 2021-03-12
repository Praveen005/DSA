//two ponter approach
// to find pair of elements from an array whose sum is equal to the given sum
//valid only for sorted array
#include<iostream>
using namespace std;
int main(){
	int a[]={1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	int sum=10;
	int i=0;
	int j=n-1;
	int sum1 = (a[i]+a[j]);
	while(i<j){
		
		if(sum1==sum){
			cout<<i<<"  "<<j<<endl;
			i++;
			j--;
		}
		if(sum<sum1){
			i++;
		}
		if(sum>sum1){
			j--;
		}
		sum1 = (a[i]+a[j]);
	}


}
