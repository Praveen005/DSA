#include<iostream>
using namespace std;
int zeros(int n){
	
	int quotient=n/5;
	int sum=quotient;
	int div=25;
	while(quotient !=0){
		quotient=n/div;
		sum=sum+quotient;
		div=div*5;
	}
	return sum;
}
int main(){
	 int k;
	 cin>>k;
	cout<<zeros(k)<<endl;

}