#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[9]={1,2,3,4,5,6,7,8,9};
	int target=10;
	int i=0;
	int j=8;
	int sum=a[i]+a[j];
	while(sum>=target){
		j--;
		sum=a[i]+a[j];
	}
	int k=i+1;
	cout<<"i= "<<i<<"		"<<"j = "<<j<<"		"<<"k = "<<k<<"		"<<endl<<endl<<endl;
	while(k<j && k>i){
		for(int l=k; l<j;l++){
		//	cout<<"l= "<<l<<endl;
			//cout<<"sum of a[i]+a[j]+a[l] "<< a[i]+a[j]+a[l]<<endl;
			if(a[i]+a[j]+a[l]==target){
				cout<<"sum of a[i]+a[j]+a[l] "<< a[i]+a[j]+a[l]<<endl<<endl;
		//		cout<<"a[ "<<i<<" ]  : "<<a[i]<<"			"<<"a[ "<<j<<" ]  :  "<<a[j]<<"			"<<"a[ "<<l<<" ]  :"<<a[l]<<endl<<endl;
				cout<<"a[ "<<i<<" ]  : "<<a[i]<<"			"<<"a[ "<<j<<" ]  :  "<<a[j]<<"			"<<"a[ "<<l<<" ]  :"<<a[l]<<endl<<endl;
				break;
			}
			
		}
	//	cout<<"j before decrement "<<j<<endl;
		j--;
	//	cout<<"j after decrement "<<j<<endl;
	//	k=i+1;
	}
}