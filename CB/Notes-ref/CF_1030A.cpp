// In Search of an Easy Problem
//code forces : 1030 A

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int response;
//	cin>>response;
	while(n>0){
		cin>>response;
		if(response==1){
			cout<<"HARD"<<endl;
			break;
		}

		n--;
	}
	if(n==0){
		cout<<"EASY"<<endl;
	}
}