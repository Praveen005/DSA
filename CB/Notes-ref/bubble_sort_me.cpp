//bubble sort algorithm

#include<iostream>
using namespace std;

void bubble_sort(int a[] , int n){
	for(int iteration =1; iteration<=n-1; iteration++){
		for(int j=0; j<=n-1-iteration; j++){
			if(a[j]>a[j+1]){
				swap(a[j] , a[j+1]);
			}
		}
	}
}




int main(){
	int a[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	bubble_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}