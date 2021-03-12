//kadane's algorithm
#include<iostream>
using namespace std;
int main(){
	int n,left,right=0;
	cin>>n;
	int a[1000];
	int cs=0,ms=0;  //ms ::maximum sum so far , cs:: current sum;
	for(int i=0; i<n;i++){
		cin>>a[i];
		cs=cs+a[i];
		cout<<"cs= "<<cs<<endl;
		if(cs<0){
			cs=0;
		}
 		 if(cs==0 and i<=right){
 		 	left=i+1;
 		 }
 		if(ms<=cs){
 			ms=cs;
 			right=i;
 		}
		// if(ms<=cs){
		// 	ms=cs;
		// }

	}
	cout<<"max sum of subarray = "<<ms<<endl;
//	cout<<left<<endl<<right<<endl;
	for(int i=left; i<=right; i++){
		cout<<a[i]<<" ";
	} 
} 

