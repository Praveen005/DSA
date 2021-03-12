//problem sort the string

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string token_extract(string s , int key){
	char* ptr = strtok((char*)s.c_str() , " ");
	while(key>1){
		ptr =strtok(NULL , " ");
		key--;
	}
	return (string)ptr;
}
int convertToInt(string s){
	int sum=0;
	int factor=1;
	for (int i=s.length()-1; i>=0; i--){
		sum +=((s[i]-'0')*factor);
		factor *=10;
	}
	return sum;
}
//defining comparator
bool numericCompare(pair<string, string>s1 , pair<string , string>s2){
	string key1, key2;
	key1=s1.second;
	key2=s2.second;
	return convertToInt(key1)>convertToInt(key2);
}

bool lexicoCompare(pair<string, string>s1 , pair<string , string>s2){
	string key1, key2;
	key1=s1.second;
	key2=s2.second;
	return key1>key2;
}


int main(){
	int n;
	cin>>n;
	string a[100];
	cin.get();
	for(int i=0; i<n;i++){
		getline(cin , a[i]);
	}
	int key;
	cin>>key;
	string ordering, reversal;
	cin>>reversal>>ordering;

	pair<string , string> strpair[100];
	for(int i=0 ; i<n; i++){
		strpair[i].first= a[i];
		strpair[i].second=token_extract(a[i] ,key);
	}
	// now sorting is to be done
	if(ordering=="numeric"){
		sort(strpair, strpair+n , numericCompare);
	}
	else{
		sort(strpair, strpair+n , lexicoCompare);
	}

	if(reversal=="true"){
		for(int i=0 ; i<n/2; i++){
			swap(strpair[i], strpair[n-1-i]);
		}
	}

	for(int i=0; i<n; i++){
		cout<<strpair[i].first<<endl;
	}

}