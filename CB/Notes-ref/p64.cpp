//longest string

#include<iostream>
#include<cstring>
using namespace std;


int main(){
	int n;
	cin>>n;
	cin.get();
	char largest[100];
	int len=0;
	int largest_len=0;

	char a[1000]={0};
	for(int i=0 ; i<n ; i++){
		cin.getline(a, 1000);
		if(strlen(a)>len){
			len=strlen(a);
			strcpy(largest,a);
		}
	}
	cout<<endl<<cout<<"strings with largest length are : "<<endl;largest<<endl;
}
