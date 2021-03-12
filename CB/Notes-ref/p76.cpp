//sorting a list of strings
//we will use sort function inbuilt in algorithm header file
//what are we doing here?
//sort as per the length of strings, if their lengths are same arrange lexicographically

#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;
bool compare(string s1 , string s2){
	if(s1.length() == s2.length()){
		return s1<s2;
	}
	return s1.length()>s2.length();
}
int main(){
	int n;
	cin>>n;
	cin.get();
	string s[100];
	for(int i=0; i<n; i++){
		getline(cin, s[i]);
	}
	sort(s , s+n , compare);


	for(int i=0; i<n; i++){
		cout<<s[i]<<endl;
	}
}