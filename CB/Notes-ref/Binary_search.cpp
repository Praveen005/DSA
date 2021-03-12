#include<iostream>
using namespace std;
int binary_search(int *b , int n, int key){
	int start=0;
	int end=n-1;
	int m=(start+end)/2;

	while(start<=end){
		if(b[m]==key){
			return m;
		}
		if(b[m]<key){
			start= m+1;
		}
		if(b[m]>key){
			end=m-1;
		}
		m=(start+end)/2;
	}
	return -1;
}

int main(){

int n;
cin>>n;
int a[100];
for(int i=0; i<n; i++){
	cin>>a[i];
}
int key;
cin>>key;

cout<<endl<<binary_search( a  , n,  key)<<endl;

}