//selection sort
#include<iostream>

using namespace std;
void selection_sort(int a[] ,int n){

	

	for(int i=0; i<n-1; i++){
		int current_minimum_index=i;
		
		for(int j=i+1 ; j<n; j++){

			if(a[j]<a[current_minimum_index]){
				current_minimum_index=j;
	
			}
			swap(a[i] , a[current_minimum_index]);
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

	selection_sort(a,n);


	 for(int i=0; i<n ; i++){
	 	cout<<a[i]<<" ";
	 }


}