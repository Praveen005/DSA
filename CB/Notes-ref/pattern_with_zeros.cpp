#include<iostream>
using namespace std;
int main(){
	int rows;
	cin>>rows;
	while(rows>0 && rows<100){
		for(int i=1; i<=rows; i++){
			cout<<i<<"	";
			int n=i-2;
			while(n>0){       // yahan pe (i-2)>0 mat karna kyun ki aage jab i-- hoga to i=0 ho jaayega, 
		                 //phir for loop ke last me wo phir se 1 ho jaayega and har baar i=1 hi rahega and loop endless chalega :)
				cout<<0<<"	";
				n--;
			}
			if(i!=1){
				cout<<i<<endl;
			}
			else cout<<endl;
		}
		break;
	}
}