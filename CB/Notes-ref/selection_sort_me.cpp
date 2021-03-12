#include<iostream>
using namespace std;
void selection_sort(int a[] , int n){
	int i=0;


	for(int i=0 ; i<n-1; i++){
		int min_so_far=i;
		int min=min_so_far;

		for(min=min_so_far;min<n;min++){
			if(a[min]<a[min_so_far]){
				min_so_far=min;
			}
		}
		swap(a[i] ,a[min_so_far] );
	//	cout<<"a[i] = "<<a[i]<<"  ";
	}
}




int main(){
	int a[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	selection_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}