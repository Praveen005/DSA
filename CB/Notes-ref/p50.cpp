#include<iostream>
using namespace std;
void spiral_print(int a[][1000] ,  int m , int n){
	int start_row=0;
	int start_col=0;
	int end_col=n-1;
	int end_row=m-1;
	while((start_row<=end_row)&& (start_col<=end_col)){
		//first row
		for(int i= start_col ; i<=end_col    ; i++){
			cout<<a[start_row][i]<<" ";
		}
		start_row++;

		for(int i=start_row  ; i<=end_row    ; i++){
			cout<<a[i][end_col]<<" ";
		}
		end_col--;
		if(end_row>start_row){
		for(int i=end_col  ; i>=start_col    ; i--){
			cout<<a[end_row][i]<<" ";
		}
		}
		end_row--;

		if(end_col>start_col){
		for(int i=end_row  ; i>=start_row   ; i--){
			cout<<a[i][start_col]<<" ";
		}
		}
		start_col++;

	}
}




int main(){

int a[1000][1000]={0};
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