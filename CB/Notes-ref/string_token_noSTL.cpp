//designing string tokenizer

#include <iostream>
#include<cstring>
using namespace std;
char* mystrtok(char* str , char delim){
	static char* input = NULL;
	if(str != NULL){
		input=str;
	}
	// below cout statement will print strlen(NULL)  after 'day'    and  so will throw a segmentation error or runtime errorB


//	cout<<"length of input is /"<<strlen(input)<<endl;
	if(input == NULL){
		return NULL;
	}



	char* output = new char[strlen(input)+1];  

	//don't write following if() statement below because it calculates   
	//because jo upar waala strlen(NULL) calculate karna suru kar dega aur phir runtime error dega  
	// ya phir segmentatio0bn fault




	// if(input == NULL){
	// 	return NULL;
	// }

	int i=0;
	for( ; input[i] != '\0'; i++){
		if(input[i] != delim){
			output[i]=input[i];
		}
		else{
			output[i]='\0';

			input = input +i+1;

			return output;
		}
	}

	output[i]='\0';
	input=NULL;
	return output;
}


int main(){
	
	char s[100] = "Today is a rainy day";
	char* ptr = mystrtok(s , ' ');
	cout<<ptr<<endl;
	if(ptr==NULL){
		cout<<"pratyush is a bad boy and also very naughty.";
	}
	  while(ptr !=NULL){
	  	ptr= mystrtok(NULL,' ');
	 	cout<<ptr<<endl;
	  }


	return 0;

}
