//rotate image  
//anticlockwise 90 degree 
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	cin.get();
	int val=1;
	int a[100][100];
	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			a[i][j]=val;
			val++;
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			cout<<a[i][j]<<"  ";
			
		}
		cout<<endl;
	}
	cout<<endl<<endl;

	for(int i=0; i<m ; i++){
		reverse(a[i] , a[i]+n);
	}
	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			cout<<a[i][j]<<"  ";
			
		}
		cout<<endl;
	}

	cout<<endl<<endl;

	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			if(i<j){
				swap(a[i][j]  , a[j][i]);
			}
			
		}
	//	cout<<endl;
	}
	for(int i=0; i<m; i++){
		for(int j=0 ; j<n ; j++){
			cout<<a[i][j]<<"  ";
			
		}
		cout<<endl;
	}

}