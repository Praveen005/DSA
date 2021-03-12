#include<iostream>
using namespace std;
bool check_prime(int n){
	int i;
	for(i=2; i<n; i++){
		if(n%i==0){
			return false;
		}
	}
	if(i==n){
		return true;
	}
}


int no_of_primes(int n1 , int n2){
	int count=0;
	for(int i=n1; i<=n2; i++){
		if(i==1){
			continue;
		}
		if(check_prime(i)==true){
		//	cout<<i<<" ";
			count++;
		}
	}
	cout<<count<<endl;
}
int main(){
	int t,n1,n2;
	cin>>t;
	while(t>0){
		cin>>n1>>n2;
		t--;
		no_of_primes(n1,n2);
	}
}