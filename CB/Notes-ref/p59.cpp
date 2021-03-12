//BINARY SEARCH
//only for sorted array
#include<iostream>
#include<cstring>
using namespace std;
int binarySearch(int a[] , int n, int key){
	int i=0;
	int j=n-1;
	int mid = (i+j)/2;
	while(i<=j){

		if(a[mid]<key){
			i=mid+1;
		}
		else if(a[mid]>key){
			j= mid-1;
		}
		else{
			cout<<mid<<endl;
			return mid;
		}
		mid = (i+j)/2;

		
	}
	return -1;
}
int main(){
 	int key,n;
 	cin>>n;
 	int a[n];
 	for(int i=0; i<n; i++){
 		cin>>a[i];
 	}
 	cin>>key;
 	cout<<binarySearch(a,n,key);
}