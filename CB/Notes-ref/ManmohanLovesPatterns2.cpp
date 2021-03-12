//  Manmohan Loves Patterns - I

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n<=1000 && n>=0){
		cout<<1<<endl;
		int i=1;
		for(int iteration=2; iteration<=n; iteration++){
			cout<<i;
			int j=iteration;
			while(j>2){
				cout<<0;
				j--;
			}
			cout<<i;
			cout<<endl;
			i++;
		}
		break;
	}
}	

