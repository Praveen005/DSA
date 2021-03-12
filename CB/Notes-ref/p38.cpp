#include<iostream>
#include<cstring>
using namespace std;
void duplicate(char array[]){
	int prev=0;
	int length= strlen(array);
	int next;
	if(length==1 || length == 0){
		return;
	}
	for(next=1; next<length; next++){
		if(array[next]!=array[prev]){
			prev++;
			array[prev]=array[next];
		}
	}
	array[prev+1]='\0';
	cout<<array<<endl;

}
int main(){
	char ch[1000];
	cin.getline(ch,1000);
	duplicate(ch);

}