#include<iostream>
using namespace std;
int main(){
	int a[100][100];
	int m,n;
	cin>>n>>m;
	cin.get();
	int val=1;
	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			a[i][j]=val;
			val++;
		}
	}
		for(int i=0; i<m; i++){
			for(int j=0 ; j<n ; j++){
				cout<<a[i][j]<<" ";
				
	}
	cout<<endl;
}

	// int j=0;
	for(int i=0; i<n; i++){
		if(i%2==0){
			for( int j=0; j<m; j++){
				cout<<a[j][i]<<" ";
			}
			cout<<"  ";
		}
		else{
			for(int j=m-1; j>=0; j--){
				cout<<a[j][i]<<" ";
			}
			cout<<"  ";
		}
	}

}