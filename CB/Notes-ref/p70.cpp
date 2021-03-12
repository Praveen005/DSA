// largest string

#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[100][100];
	int n;
	cin>>n;
	cin.get();
	for(int i=0; i<n ; i++){
		cin.getline(a[i] , 100);
	}
	char largest_string[100];
	int largest_length=0;
	int index;
	for(int i=0 ;i<n ; i++){
		if(strlen(a[i])>largest_length){
			largest_length=strlen(a[i]);
			index=i;
			strcpy(largest_string , a[i]);
		}
	}
	cout<<"index= "<<index<<endl<<largest_string<<endl;
}