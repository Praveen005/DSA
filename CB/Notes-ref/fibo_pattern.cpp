#include<iostream>
using namespace std;
int main(){
	int rows;
	cin>>rows;
	while(rows>0 && rows<100){
		if(rows==1){
			cout<<0<<endl;
		}
		else if(rows==2){
			cout<<"0"<<endl<<"1 1"<<endl;
		}
		else if(rows>2){
			cout<<"0"<<endl<<"1 1"<<endl;
		}
		int p=1,q=1,r,l;
		for(int i=3 ; i<=rows ; i++){
			l=i;
			while(l>0){
				r=p+q;
				p=q;
				q=r;
				cout<<r<<" ";
				l--;
			}
			cout<<endl;
		}
		break;
	}
}