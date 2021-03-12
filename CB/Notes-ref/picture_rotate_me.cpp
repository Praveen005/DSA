#include<iostream>
using namespace std;
void rotate_matrix(int a[][100] , int m , int n){
	for(int i=m-1; i>=0; i--){
		for(int j=0; j<n; j++){
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
}



int main(){
	int m;
	int val =1;
	cin>>m;
	int n=m;
	int a[100][100];
	for(int i=0;i<m; i++){
		for(int j=0; j<n; j++){
			a[i][j]=val;
			val++;
		}
	}
	rotate_matrix(a,m,n);
}