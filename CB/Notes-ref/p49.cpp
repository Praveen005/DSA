#include<iostream>
using namespace std;
void spiral_print(int a[][100] , int m , int n){

// m rows and   n columns
	int sr=0;
	int er=m-1;
	int sc=0;
	int ec=n-1;

	//start rows/columns will increase and   end rows/columns will decrease
	while(sc<=ec && sr<=er){
		for(int i=sc; i<=ec;i++){
			cout<<a[sr][i]<<" ";
		}
		sr++;



		for(int i=sr; i<=er;i++){
			cout<<a[i][ec]<<" ";
		}
		
		ec--;

		if(sr<er){
			for(int i=ec; i>=sc;i--){
				cout<<a[er][i]<<" ";
			}
		}
		er--;

		if(sc<ec){
			for(int i=er; i>=sr;i--){
				cout<<a[i][sc]<<" ";
			}
		}
		sc++;


	}
}




int main(){
int a[100][100]={0};
int m,n;
int val=1;
cin>>m>>n;
	for(int row=0 ; row<m; row++){
		for(int col=0; col<n; col++){
			a[row][col]=val;
			val++;
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
	spiral_print(a,m,n);
}	