#include<iostream>
using namespace std;
void anticlockSpiralPrint(int a[][100], int m , int n){
	int sr=0;
	int er=m-1;
	int sc=0;
	int ec=n-1;
	while(sr<=er && sc<=ec){
		//sr--er
		//col fixed :: sc
		for(int row=sr;row<=er; row++){
			cout<<a[row][sc]<<", ";
		}
		sc++;

		//sc--ec
		//row fixed  :: er
		for(int col=sc;col<=ec; col++){
			cout<<a[er][col]<<", ";

		}
		er--;
		//er--sr
		//col fixed :: ec
		if(sc<=ec){
		for(int row=er;row>=sr; row--){
			cout<<a[row][ec]<<", ";
		}
		}
		ec--;

		//ec--sc
		//row fixed ::sr
		if(sr<=er){
		for(int col=ec;col>=sc; col--){
			cout<<a[sr][col]<<", ";
		}
		}
		sr++;
	}
	cout<<"END"<<endl;
}


int main(){
	int m, n;
	cin>>m>>n;
	
	
	int a[100][100];
	for(int row=0; row<m; row++){
		for(int col=0; col<n ; col++){
			cin>>a[row][col];
			
		}
	}
		for(int row=0; row<m; row++){
		for(int col=0; col<n ; col++){
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	anticlockSpiralPrint(a,m,n);

}