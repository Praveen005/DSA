#include<iostream>
using namespace std;
int main(){
	int a[100][100]={0};
	int k=1;
	// m - rows    ;  n- columns
	int m,n;
	cin>>m>>n;
	cout<<endl<<endl;
	
	for(int row=0 ; row<m; row++){
		for(int col=0 ; col<n ; col++){
			a[row][col]=k;
			cout<<a[row][col]<<" ";
			k=k+1;
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;

	for(int col=0; col<n; col++){
		if(col%2==0){
			for(int row=0; row<m; row++){
				cout<<a[row][col]<<" ";
			}
			//cout<<endl;
		}


		else {
			for(int row=m-1; row>=0 ; row--){
				cout<<a[row][col]<<" ";
			}
		//	cout<<endl;

		}


	}
}