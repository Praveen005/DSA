#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int k;
	k=1;
	char a[100] = "blocks";
	
	char b[100];
	int l= strlen(a);
//	cout<<l;

	int b1=0;
	for(int i=l-k ; i<l ; i++){
		b[b1]=a[i];
		b1++;
	}

	for(int i=l-k-1; i>=0; i--){
		
		a[i+k]=a[i];
		
	}

	for(int i=0; i<k; i++){
		a[i]=b[i];
	}

	for(int i=0; i<l ; i++){
		cout<<a[i]<<" ";
	}

}