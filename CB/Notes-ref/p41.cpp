//insertion sort

#include<iostream>
using namespace std;



void insertion_sort(int a[] , int n){
//	int l=n-1;

//	int j=1;
	int i;
	for(int j =1; j<=n-1; j++){
		i=j-1;
		int e=a[j];
		while(i>=0 && a[i]>e){
			a[i+1]=a[i];
		//	j--;
			i--;

		}
		a[i+1]=e;
	}
}

// void insertion_sort(int a[] , int n){

// 	for(int i =1; i<=n-1; i++){
// 		int e=a[i];
// 		int j=i-1;
// 		while(j>=0 && a[j]>e){
// 			a[j+1]=a[j];
// 			j=j-1;
// 		}
// 		a[j+1]=e;


// 	}
// }



int main(){
	int a[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	insertion_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}