#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[100];
	int n;
	cin>>n;
	int len;
	int largest_len=0;
	char largest[100];
	cin.get();
	for(int i=0 ; i<n; i++){
		cin.getline(a,100);
		len=strlen(a);
		if(len>largest_len){
			largest_len=len;
			strcpy(largest , a);
		}
		
	}
	cout<<largest <<"  "<<largest_len<<endl;
}