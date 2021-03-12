//prime seive
#include<iostream>

using namespace std;
#define ll long long
bool prime_seive(int a[] ){

	//only multiples of of 3 can be prime 
	for(int i=3; i<=1000000; i+=2){
		a[i]=1;
	}
	for(ll i=3 ; i<=1000000; i+=2){
	//	if(a[i] == 1){
		for(ll j=i*i;  j<=1000000; j +=i ){
			a[j]=0;
		}
	}
	
	a[2]=1;
	a[0]=a[1]=0;
} 
int main(){
	int iteration;
	cin>>iteration;
	while(iteration>0){
	 int n1,n2;
	 cin>>n1>>n2;
	int a[1000000]={0};
	prime_seive(a);
	int count=0;
	for(int k=n1; k<=n2;k++){
		if(a[k]==1){
			count++;
		}
	}
	cout<<endl<<count<<endl;
	iteration--;
}
	
}