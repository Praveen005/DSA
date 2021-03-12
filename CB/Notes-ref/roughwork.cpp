//bubble sort

#include<iostream>
using namespace std;
void bubble_sort(int a[], int n){
	for(int iteration =0; iteration<n-1; iteration++){
		for(int i=0; i<n-1-iteration; i++){

			cout<<"i : "<<i<<endl;
            cout<<"a[ "<<i<<" ] : "<<a[i]<<"\t  \t";
               cout<<"a[ "<<i+1<<" ] : "<<a[i+1]<<endl;

			if(a[i]>a[i+1]){
				swap(a[i] , a[i+1]);
			}

			cout<<"After swapping : "<<endl;
			cout<<"a[ "<<i<<" ] : "<<a[i]<<"\t  \t";
            cout<<"a[ "<<i+1<<" ] : "<<a[i+1]<<endl<<endl;

		}
	}
}


int main(){
	// int n;
	// cin>>n;
	int a[]= {5,4,3,2,1};
	// for(int i=0; i<n ; i++){
	// 	cin>>a[i];
	// }

	bubble_sort(a,5);


	 for(int i=0; i<5 ; i++){
	 	cout<<a[i]<<" ";
	 }


}