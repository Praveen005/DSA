#include<iostream>
using namespace std;
int main(){
	int a[5]={2,8,6,9,44};
	for(int i=0;i<5;i++){
		
		for(int j=0;j<5-i;j++){
			
			for(int k=i;k<=j;k++){
				cout<<a[k]<<" ";
				
			}
			cout<<endl;
		}
	}
}