#include<iostream>
using namespace std;
int fibonacci(int n){
	int a=0, b=1, c;
	for(int i=1; i<=n-2;i++){
		c=a+b;
		
		a=b;
		b=c;
	}
	return c;
}

int main(){
	int n;
	cin>>n;
	cout<<"required fibonacci number is "<<fibonacci(n)<<endl;
}