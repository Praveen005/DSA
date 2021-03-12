#include<iostream>
using namespace std;
int main(){
	int i=0;
	char ch[1000];
	cin>>ch;
	if(ch[0]=='9'){
		i++;
	}

	for(  ; ch[i] != '\0' ; i++){
		int k= ch[i]- '0' ;					// '0' = 48 in ascii  '1' = 49    '2' = 50 ...so on
		if (k>4){							//ch[i]-'0' means let ch[i]= '8'   '8' =56 and '0' = 48  means '8' - '0' = 8 and this 8 is integer which is stored in int k;
			k=9-k;
		}
		ch[i]= k +'0';
	}
	cout<<ch<<endl;
}