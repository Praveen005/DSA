//Designing string tokenizern

#include<iostream>
#include<cstring>
using namespace std;
char* mystrtok(char* str , char delim){
	static char* input=NULL;
	if(str != NULL){
		input=str;
	}
	if(input==NULL){
		return NULL;
	}
	// new jo hai uska use dynamic memory allocation me hota hai
	// matlab jab hame pata nahi hota ki ise kitna memory provide karna hai
	// ab sawal uthhta hai ki ye strlen(input)+1 kyun?
	// wo iss liye ki , consider a case when delimeter is at last
	// in this case we need to assign whole length to output[]  +1 to strore  '\0'
	// aur thoda jyada bhi hoga ek aadh box to kya issue hai :)
	char* output = new char[strlen(input)+1];
	int i=0;
	for(; input[i] !='\0' ;i++){
		if(input[i] != delim){
			output[i]=input[i];
		}
		else{
			output[i]='\0';
			input=input+i+1;
			return output;

		}
	}
	output[i]='\0';
	input=NULL;
	return output;
}


int main(){
	string s="pratyush is a very bad boy and naughty as well";
	char*ptr = mystrtok((char*)s.c_str(), ' ');
	cout<<ptr<<endl;
	while(ptr != NULL){
		ptr= mystrtok(NULL ,' ');
		cout<<ptr<<endl;
	}
}