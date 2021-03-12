#include<iostream>
using namespace std;
int main(){
	char a[]= "hello world !";
//	cout<<sizeof(a)<<endl;											// sizeof(a) also counts '\0' here
	int n= sizeof(a)-2;

	for(int i=n; i>=0; i--){
	 	cout<<a[i];
	 	
	}
}
