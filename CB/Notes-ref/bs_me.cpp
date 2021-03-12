#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a[100];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int end=n-1;
	int start=0;
	int m = (start+end)/2;
	int key;
	cin>>key;
	while( start<end){
		if(key<a[m]){
			end=m-1;
		}
		else{
			start=m+1;
		}

		// if(key== a[m]){
		// 	break;
		// }
		m=(start+end)/2;
	}
	cout<<m<<endl;
	return 0;
}