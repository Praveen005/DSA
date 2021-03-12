#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char ch[]){
	int i=0;
	int j= strlen(ch)-1;
	while(i<j){
		if(ch[i]==ch[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	return true;
}
int main(){
	char a[1000];
	cin>>a;
	if(palindrome(a)==true){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}

}