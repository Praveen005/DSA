#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char ch[1000]={'\0'};

	cin>>ch;
	int l= strlen(ch);
	//cout<<" length of string is "<<l<<endl;
	int k;
	cin>>k;
	for(int i=l-1 ; i>=0 ; i--){
		ch[i+k]=ch[i];

	}
	 int p=l;
	for(int i=0 ; i<k ; i++){
		ch[i]=ch[p];
		p++;
	}
	//cout<<"l = "<<l<<endl;
	ch[l]='\0';
	//cout<<ch[l]<<endl<<ch[l-1]<<endl;
	cout<<"Rotated array is "<<ch<<endl;
	
	
	
}