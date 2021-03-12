//string class;

#include<iostream>
#include<string>
using namespace std;
int main(){

	string s1 ="pratyush is a good boy ";
	string s2 ="and also very clever" ;
	s1.append(5 ,'*');
	cout<<s1<<endl;
	s1.append(s2, 0 ,5);
	cout<<s1<<endl;
//	s2.clear();
	cout<<s2<<endl;
	s1=s1+s2;
	cout<<s1<<endl;
	char a[]="12345";
	string s3(a);
	cout<<s3<<endl<<s3.length()<<endl;
	if(s1>s2){
		cout<<"p"<<endl;
	}
	else{
		cout<<"Q"<<endl;
	}
	cout<<s2.compare(s1)<<endl;
	int index=s2.find("very");
	string word ="very";
	s2.erase(index ,word.length() );
	cout<<s2<<endl;
	 for(int i=0; i<s1.length() ;i++){
	 	cout<<s1[i]<<":";
	 }
	// instead of using loop to iterate over the characters of the string you can use inbuilt iterators
	 cout<<endl<<endl;

	for(auto iit =s1.begin() ; iit !=s1.end() ;iit++){
		cout<<(*iit)<<":";
	}

}