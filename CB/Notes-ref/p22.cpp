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


int no_of_primes(int number){
	int count=0;
	for(int i=2; i<=number; i++){
		if(check_prime(i)==true){
			cout<<i<<" ";
			count++;
		}
	}
	cout<<endl<<"No of prime numbers less than " <<number <<" = "<<count<<endl;
}
int main(){
	int number;
	cin>>number;
	no_of_primes(number);
}