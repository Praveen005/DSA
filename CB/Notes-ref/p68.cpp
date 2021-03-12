#include<iostream>
using namespace std;
int main(){
	int a[100][100]={0};
	int n,m;
	int val=1;
	cin>>n>>m;
	cin.get();
	for(int i=0; i<n; i++){
		for(int j=0;j<m; j++){
			a[i][j]=val;
			val++;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0;j<m; j++){
			cout<<a[i][j]<<" ";
			
		}
		cout<<endl;
	}

}