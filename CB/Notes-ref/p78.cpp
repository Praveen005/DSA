// design a string tokenizer


#include<iostream>
#include<cstring>
using namespace std;
char* mystrtok(char* str, char delim){
	static char* input=NULL;
	if(str != NULL){
		input=str;
	}
	if(input== NULL){
		return NULL;
	}
	char* output= new char[strlen(input)+1];
	int i=0;
	for( ; input[i] !='\0'; i++){
		if(input[i] != delim){
			output[i]=input[i];
		}
		else{
			output[i]= '\0';
			input =input+i+1;
			return output;
		}
	}
	output[i]='\0';
	input=NULL;
	return output;

}



int main(){
	string s ="Today is rainy day and very cloudy as well";
	char* ptr = mystrtok((char*)s.c_str() , ' ');
	cout<<ptr<<endl;
	while(ptr != NULL){
		ptr = mystrtok(NULL , ' ');
		cout<<ptr<<endl;
	}
}