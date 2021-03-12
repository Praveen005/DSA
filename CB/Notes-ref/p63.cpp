//bubble_sort 

#include<iostream>
using namespace std;
void bubble_sort(int a[] , int n){
	for(int iteration=0 ; iteration<=n-2; iteration++){
		int i=0;
		for(int j=1; j<n-iteration; j++){  //  no of swappings will decrease after each iteration 
											//  because largest no. will bubble out and 'll get stored at the last. 
			if(a[i]>a[i+1]){
				swap(a[i] , a[i+1]);
			}
			i++;
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
	bubble_sort(a, n);
	for(int i=0 ; i<n; i++){
		cout<<a[i]<<" ";
	}
}