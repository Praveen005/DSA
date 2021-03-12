//selection sort
#include<iostream>
#include<cstring>
using namespace std;
void selection_sort(int a[] , int n){
	for(int i=0 ; i<n-1 ; i++){
		
		int min=a[i];
		int min_index=i;   // I had not inialized this min_index earlier that so for each 
		//iteration previous min_index was carried and thus was giving wrong result
		for(int j= i ; j<n ; j++){
			if(a[j]<min){
				min=a[j];
				min_index=j;
			}
		}
		swap(a[i] , a[min_index]);
	}
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n ; i++){
		cin>>a[i];
	}

	selection_sort(a,n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	

}
