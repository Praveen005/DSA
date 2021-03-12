//check if given array is sorted or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dec_sort(int a[] , int n){

	if(n==0 || n==1){
		return 1  ;
	}

	if(a[n-1]>a[n-2]){
		return 0;
	}
	return dec_sort(a , n-1);
	
}

int inc_sort(int a[] , int n){

	if(n==0 || n==1){
		return 1  ;
	}

	if(a[n-1]<a[n-2]){
		return 0;
	}
	return inc_sort(a , n-1);
	
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[n];
	}
	if(dec_sort(a,n)==1 || inc_sort(a,n)==1){
		cout<<"yes , array is sorted"<<endl;
	}
	else{
		cout<<"array is not sorted"<<endl;
	}

}