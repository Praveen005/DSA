//insertion sort;

#include<iostream>
using namespace std;
void insertion_sort(int a[] , int n){
	for(int i=0 ; i<n-1; i++){
		int j=i+1;
		int e= a[j];
		while( i>=0 and a[i]>e){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=e;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n ; i++){
		cin>>a[i];
	}

	insertion_sort(a,n);


	 for(int i=0; i<n ; i++){
	 	cout<<a[i]<<" ";
	 }


}