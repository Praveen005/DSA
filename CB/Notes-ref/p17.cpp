#include<iostream>
using namespace std;
int main(){
	char ch[100];
	cin>>ch;
	int i=0;
	if(ch[0]=='9'){
		i++;
	}
	for(  ; ch[i] !='\0' ; i++){
		int n1=ch[i] - '0';
		if(n1>4){
			n1=9-n1;
		ch[i]=n1+'0';
		}


	}
	cout<<ch<<endl;
	
}