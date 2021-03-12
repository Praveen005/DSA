//sum of two arrays problem
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int sum(int a[] , int b[] ,int n , int m, int arr3[]){

	int arr_size=0;
	int n1= max (n,m);
//	cout<<"n1 = "<<n1<<endl;
	int carry=0;
	int s;
	int e;
	for(int i=0 ; i<n1; i++){
		s=a[i]+b[i]+carry;
		arr3[arr_size]=s%10;
		carry=s/10;
   //     cout<<"array size = "<<arr_size<<endl;
		arr_size++;
		
	}
 //   carry=0;
 //   cout<<"carry ="<<carry<<endl;
	while(carry>0){
     //   cout<<"array size = "<<arr_size<<endl;
		arr3[arr_size]=carry%10;
		arr_size++;
		carry=carry/10;
	}
	return arr_size;
}
int main(){
	int n;
	cin>>n;
	int arr1[100]={0};
	for(int i=n-1; i>=0; i--){
		cin>>arr1[i];
	}
	int m;
	cin>>m;
	int arr2[100]={0};
	for(int i=m-1; i>=0; i--){
		cin>>arr2[i];
	}
	int arr3[100]={0};

	int x;
    x=sum(arr1, arr2, n,m,arr3);
//	cout<<"x = "<<x<<endl;
	for(int i=x-1; i>=0; i--){
		cout<<arr3[i];
	}
}