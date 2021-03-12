#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool lexicoCompare(string a, string b){
	return a>b;
}
int main(){
	int itr;
	cin>>itr;
	while(itr>0){
	int n;
	cin>>n;
	cin.get();
	string strarray[100];
	for(int i=0; i<n; i++){
		getline(cin , strarray[i],' ');
	}
	string s;
	sort(strarray , strarray+n, lexicoCompare);
	for(int i=0; i<n; i++){
		s=s.append(strarray[i]);
	}



	for(int i=0; i<n; i++){
		cout<<strarray[i];
	}










	itr--;
}
}