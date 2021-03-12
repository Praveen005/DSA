#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
// first step is to extract token from the input string
// tab hi na compare karoge na bhai :)

string extractToken(string str, int key){

	// below:  ye jo hai wo argument me character array leta hai , so we converted the string 'str' by type casting the string
	// and using the following  inbuilt function
	char* ptr = strtok((char*) str.c_str() , " ");
	while(key>1){
		ptr = strtok(NULL , " ");
		key--;
	}
	//below: since ptr is a character pointer/array (although both are not same)
	//so we need  to typecast it to convert this into a string
	return (string)ptr;

}

//2nd step is sorting the tokens
//two ways: lexicographically and numerically

int ConvertToInt(string s){
	int ans=0;
	int p=1;
	for(int i= s.length()-1 ; i>=0 ; i-- ){
		ans += ((s[i]-'0')*p);
		p=p*10;

	}
	return ans;
}

bool numericCompare(pair <string, string> s1 , pair<string , string> s2){
	string key1 , key2;
	key1= s1.second;
	key2= s2.second;

	return ConvertToInt(key1)< ConvertToInt(key2);
}


bool lexicocompare(pair <string, string> s1 , pair<string , string> s2){
	string key1 , key2;
	key1= s1.second;
	key2= s2.second;

	return key1 < key2;
}




int main(){

	int n;
	cin>>n;
	cin.get();
	string s[100];
	for(int i=0 ; i<n ; i++){
		getline(cin, s[i]);

	}

	int key;
	string reversal, ordering;
	cin>>key;
	cin>>reversal>>ordering;

	// stored the vaLUE IN PAIR

	pair <string, string> pString[100];
	for(int i=0; i>n ; i++){
		pString[i].first=s[i];
		pString[i].first=extractToken(s[i] , key);
		
	}

	//SORTING

	if(ordering=="numeric"){
		sort(pString , pString+n , numericCompare);
	}


	else if(ordering=="lexicographic"){
		sort(pString , pString+n , lexicocompare);
	}
	if(reversal=="true"){
		for(int i=0; i<n/2; i++){
		 	swap(pString[i] , pString[n-i-1]);
		}
	}

	for(int i=0 ; i<n ; i++){
		cout<<pString[i].first<<" ";
	}

	return 0;

}