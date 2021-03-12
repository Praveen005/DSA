#include<iostream>
#include<algorithm>
using namespace  std;
void rotate(int a[][100] , int n){
	for(int i=0; i<n; i++){
		reverse(a[i] , a[i] + n);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap(a[i][j] , a[j][i]);

			}

		}
	}
	
}




int main(){
	//m -- rows   & n-- columns
	int n;
	cin>>n;
	int m=n;
	int a[100][100];
	for(int row=0; row<m; row++){
		for(int col=0; col<n ; col++){
			cin>>a[row][col];
			
		}
	}

	rotate(a,n);
	for(int row=0; row<m; row++){
		for(int col=0; col<n ; col++){
			cout<<a[row][col]<<" ";
			
		}
		cout<<endl;
	}


}