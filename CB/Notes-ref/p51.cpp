//string class

// never forget to use the header file # include<string>
//because a few functions may (   ???   ) not work without this header file  :)

#include<iostream>
//#include<string>
using namespace std;
int main(){
	string s0;
	string s1("hello world");
	cout<<s1<<endl;
	string s2= "hello prateek !";
	string s3(s2);
	cout<<s2<<endl<<s3<<endl;
	//this compares lexicographicaly
	cout<<s1.compare(s2)<<endl;
	cout<<s0.length()<<endl;
	s3.clear();
	cout<<s3<<endl;
	cout<<s3.length()<<endl;
	s2.append(" pratyush is a bad boy.");
	cout<<s2<<endl;
	s2+=" and naughty as well";
	cout<<s2<<endl;
	if(s2.empty()){
		cout<<"yes indeed."<<endl;
	}
	string s4 ("mango is a fruit");
	int idx= s4.find("fruit");
	cout<<idx<<endl;
	string word= "apple";
	int l= word.length();
	cout<<l<<endl;
	s4.erase(idx ,l);
	cout<<s4<<endl;
	cout<<s4[0]<<endl;

	for(int i=0; i<s4.length() ; i++){
		cout<<s4[i]<<":";
	}
	cout<<endl;
	for(auto it =s4.begin() ; it !=s4.end() ; it++){
		cout<<(*it)<<":" ;
	}
	cout<<endl;

	for(string::iterator it =s4.begin() ; it !=s4.end() ; it++){
		cout<<(*it)<<":" ;
	}
	cout<<endl;

	for(auto ram :s4){
		cout<<ram<<":";
	}
	
}
