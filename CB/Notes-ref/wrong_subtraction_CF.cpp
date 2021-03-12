//CODEFORCES problem   
//wrong subtraction
#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	int num;
	cin>>num;
	cin>>k;
	for(int i=1; i<=k; i++){
//	cout<<"number before = "<<num<<endl;
		if(num%10 == 0){
			num=num/10;
		}
		else
		num=num-1;

	}
	cout<<num<<endl;
}
