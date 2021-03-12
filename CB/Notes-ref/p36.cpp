#include<iostream>
using namespace std;
void readline(char b[] ,int  maxlength){
	char ch=cin.get();
	int i=0;
	while(ch !='\n'){
		b[i]=ch;
		i++;
		if(i== maxlength-1){
			break;
		}
		ch=cin.get();
	}
	b[maxlength-1]='\0';

}
int main(){

	char ch[1000]={0};
	readline(ch , 1000);

	cout<<ch<<endl;

}