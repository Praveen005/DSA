#include<iostream>
using namespace std;
void rotate_picture(int a[][1000], int m){
	for(int row=0; row<m; row++){
		int i=0, j=m-1;
		while(i<j){
			swap(a[row][i] , a[row][j]);
			i++;
			j--;
		}
	}


	
	for(int i=0; i<m;i++){
		for(int j=0; j<m; j++){
			if(i>j){
				swap( a[i][j], a[j][i]);
			}
		}

	}
}



int main(){
	int n;
	cin>>n;
	int a[1000][1000];
	int m=n;

	//matrix is N*N   m rows  n columns    m=n

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	rotate_picture(a, m);
}