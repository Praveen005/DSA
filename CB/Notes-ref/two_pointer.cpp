//two pointer approach
// valid only for sorted array

#include<iostream>
using namespace std;
int main(){
	int a[]={1,2,3,4,5,6,7,8};
	int current_sum=0;
	int sum=9;
	int i=0;
	int j= sizeof(a)/sizeof(int)-1;
	while(i<j){
		current_sum=a[i]+a[j];
		if(current_sum<sum){
			i++;
		}
		if(current_sum>sum){
			j--;
		}
		if(current_sum==sum){
			cout<<a[i]<<"  and  "<<a[j]<<endl;
		}
		i++;
		j--;
	}
}