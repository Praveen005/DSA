#include<iostream>
using namespace std;
int main(){
	char ch[11]={0};
	cin>>ch;
	int count=0;

	for(int i=0; ch[i] !='\0' ; i++){
		count++;
	
	}
	for(int i=count; i>=0; i--){
		cout<<ch[i];
	}
}