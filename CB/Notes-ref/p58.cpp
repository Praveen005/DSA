#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string getToken(string str , int key){
	char* ptr =strtok((char*)str.c_str() ," " );
	while(key>1){
		ptr=strtok(NULL , " ");
		key--;
	}
	return (string)ptr;
}
int stringToInt(string s){
	int sum=0;
	int p=1;
	for(int i=s.length()-1 ; i>=0 ; i--){
		sum +=((s[i]-'0')*p);
		p =p*10;
	}
	return sum;
}
bool numericCompare(pair <string, string> s1  , pair <string, string> s2){
	string key1=s1.second;
	string key2= s2.second; 
	return stringToInt(key1)< stringToInt(key2);
}

bool lexicoCompare(pair <string, string> s1  , pair <string, string> s2){
	string key1=s1.second;
	string key2= s2.second; 
	return key1< key2;
}



int main(){
	int n; 
	cin>>n;
	cin.get();
	string s[100];
	for(int i=0; i<n; i++){
		getline(cin,s[i]);
	}
	int key;
	string reversal,ordering;
	cin>>key;
	cin>>reversal>>ordering;

	pair <string ,string> stringPair[100];
	for(int i=0 ; i<n ; i++){
		stringPair[i].first=s[i];
		stringPair[i].second=getToken(s[i] ,key);
	}
	//sorting
	if(ordering=="numeric"){
		sort(stringPair , stringPair+n , numericCompare );
	}
	else{
		sort(stringPair , stringPair+n , lexicoCompare);
	}

	if(reversal=="true"){
		for(int i=0; i<n/2; i++){
			swap(stringPair[i] , stringPair[n-i-1]);
		}
	}

	for(int i=0; i<n; i++){
		cout<<stringPair[i].first<<endl;
	}

	return 0;
}