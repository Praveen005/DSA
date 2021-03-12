//we are now into STRING TOKENIZER
// the inbuilt function inside the CSTRING header file is    strtok()
//it returns character pointer
//it takes input a character pointer and a  character array of DELIMITER i.e this delimiter can be a string
//after the first call is over i.e in subsequent calls we will pass
// NULL to the function  strtok() with a DELIMITER

#include<iostream>
#include<cstring>
using namespace std;



int main(){
	string s ="Today is. rainy .day";
	char* ptr = strtok((char*)s.c_str() , ".");
	cout<<ptr<<endl;
	while(ptr != NULL){
		ptr = strtok(NULL , ".");
		cout<<ptr<<endl;
	}
}