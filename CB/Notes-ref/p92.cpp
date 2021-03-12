//chewbacca and number

#include<iostream>
#include<cstring>
using namespace std;


int main(){
	char ch[100];
	
	cin>>ch;
	int i=0;
	if(ch[0]=='9'){
			i++;
		}
	for(  ; i<strlen(ch); i++){
		int num;
		num=ch[i]-'0';

		if(num>4){
			num=9-num;

			ch[i]=num+'0';
		}

	}
	cout<<ch;	
}