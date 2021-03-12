#include<iostream>
using namespace std;
bool checkprime(int n){
	int i;
	for( i=2; i*i<n; i++){
		if(n%i==0){
			return false;
			break;
		}
	}
	if(i*i >n){
		return true;
	}
}


void no_of_prime(int num1 ,int num2){
	int count=0;
	for(int i=num1+1; i<num2;i++){
		if(checkprime(i)==true){
			count++;
			cout<<endl<<i<<" ";

		}
	}
	cout<<endl<<"no of primes = "<<count<<endl;
}
int main(){
	int num1, num2;
	cin>>num1>>num2;
	//we are checking no of prime numbers between a and b;
	no_of_prime(num1 ,num2);
}
