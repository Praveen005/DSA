#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100];
	int left[100], right[100];

	for(int i=0; i<n;i++){
		cin>>a[i];
	}

	left[0]=a[0];
	for (int i=1 ; i<n;i++){
		left[i]= max(left[i-1], a[i]);
	}

	right[n-1]=a[n-1];
	for(int i=n-2; i>=0; i--){
		right[i]= max(right[i+1], a[i]);
	}

	// for(int i=0; i<n; i++){
	// 	cout<<a[i]<<endl<<left[i]<<endl<<right[i]<<"."<<endl<<endl;
	// }

	int cum[100];
	cum[-1]=0;
	for(int i=0; i<n; i++){
		cum[i]=cum[i-1]+ (min(left[i], right[i])-a[i]); 
		
	}
  
	cout<<"total units of water stored = "<<cum[n-1];
}
