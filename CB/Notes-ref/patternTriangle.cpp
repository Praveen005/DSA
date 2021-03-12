#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int tab=n-1;
	for(int i=1; i<=n; i++){
		int tab1=tab;
	//	int tab2=tab;
		while(tab1>0){
			cout<<" \t";
			tab1--;
		}
		int k=i;
		int j=i;
		while(k>0){
			cout<<j<<"\t";
			k--;
			j++;
		}
		j=j-2;
		k=i-1;
		while(k>0){
			cout<<j<<"\t";
			j--;
			k--;
		}
		cout<<endl;
		tab--;
	}
}