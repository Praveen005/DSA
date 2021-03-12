//this has some error please weed out or refer to p57.cpp

#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

//this block is correct

string extractStringAtKey(string str, int key){

	char* s = strtok((char*)str.c_str()," ");  // char* wale bracket ke baad space tha
	while(key>1){
		s = strtok(NULL , " ");
		key--;
	}

	return (string)s;

}
//this block is correct

// this block is correct

int ConvertToInt(string s){
	int ans=0;
	int p=1;
	for(int i= s.length()-1 ; i>=0 ; i-- ){
		ans += ((s[i]-'0')*p);
		p=p*10;

	}
//	cout<<"string to int is =/"<<ans<<endl;
	return ans;
}

//till here

bool numericCompare(pair <string, string> s1 , pair<string , string> s2){
	string key1 , key2;
	key1= s1.second;
	key2= s2.second;

	return ConvertToInt(key1)< ConvertToInt(key2);
}


bool lexicoCompare(pair <string, string> s1 , pair<string , string> s2){
	string key1 , key2;
	key1= s1.second;
	key2= s2.second;

	return key1 < key2;
}




int main(){

	int n;
	cin>>n;
	cin.get();
	string a[100];
	for(int i=0 ; i<n ; i++){
		getline(cin, a[i]);

	}

	int key;
	string reversal, ordering;
	 cin>>key;
	 cin>>reversal>>ordering;



	pair <string, string> strPair[100];
	for(int i=0; i<n ; i++){    ///////// yaha galti hai   i>n likha tha   ;(
		strPair[i].first=a[i];
		strPair[i].second=extractStringAtKey(a[i] , key);
		
	}



	if(ordering=="numeric"){
		sort(strPair , strPair+n , numericCompare);
	}


	else {
		sort(strPair , strPair+n , lexicoCompare);
	}
	if(reversal=="true"){
		for(int i=0; i<n/2; i++){
		 	swap(strPair[i] , strPair[n-i-1]);
		}
	}

	for(int i=0 ; i<n ; i++){
		cout<<strPair[i].first<<endl;
	}

	return 0;

}