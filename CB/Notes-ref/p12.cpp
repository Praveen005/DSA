#include<iostream>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int n =s.length();
	for(int i=0 ; i<n; i++){
		for(int j=i; j<n; j++){
			for(int k=i; k<=j; k++){
				cout<<s[k]<<" ";
			}
			cout<<endl;
		}
	}	
}