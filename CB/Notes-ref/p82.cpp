/*
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
*/

#include<iostream>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int val=11;
	int a[100][100];
	for(int row =0; row<m; row++){
		for(int col=0; col<n; col++){
			a[row][col]=val;
			val++;
		}
		val+=6;
	}
	for(int col =0; col<n; col++){
		if(col%2==0){
			for(int row=0; row<m; row++){
			cout<<a[row][col]<<", ";
			
		}
		}
		else{
			for(int row=m-1; row>=0; row--){
			cout<<a[row][col]<<", ";
			
		}
		}	
		
	}
	cout<<"END"<<endl;
}