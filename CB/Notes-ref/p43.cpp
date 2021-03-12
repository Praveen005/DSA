#include<iostream>
using namespace std;
bool order(int a, int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int p=0 ; p<n ; p++){
		cin>>a[p];
	}
	int i;
	
	for(i=0; i<n-1; i++){
		 if(order(a[i], a[i+1])==true){
		
		 }
		 else{
		 	break;
		 }
		
	}
	

	// if(i==n-1){
	// 	cout<<"decending"<<endl;
	// }
	
	int j;
	for(j=0; j<n-1; j++){
		if(order(a[j], a[j+1])==false){
		
		}
		 else{
		 	break;
		 }
		
	}

// if(j==n-1){
// 		cout<<"ascending"<<endl;
// 	}


	if(i==n-1 || j==n-1){
		cout<<"true"<<endl;
	}
	else {
		cout<<"false"<<endl;
	}
}