// this is not insertion sort

#include<iostream>
using namespace std;

void insertion_sort(int a[] , int n){

	for(int iteration =1; iteration<n-1; iteration++){
		int k;int var;
		for(int j=0; j<=n-1-iteration; j++){
			k=j+1;
			if(a[j]>a[k]){
				var=a[k];
				a[k]=a[j];
				a[j]=var;
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
	insertion_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}