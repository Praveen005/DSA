//bubble sort

#include<iostream>
using namespace std;
void bubble_sort(int a[], int n){
	for(int iteration =1; iteration<=n-1; iteration++){
		for(int i=0; i<=n-1-iteration; i++){
			if(a[i]>a[i+1]){
				swap(a[i] , a[i+1]);
			}
		}
	}
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n ; i++){
		cin>>a[i];
	}

	bubble_sort(a,n);


	 for(int i=0; i<n ; i++){
	 	cout<<a[i]<<" ";
	 }


}