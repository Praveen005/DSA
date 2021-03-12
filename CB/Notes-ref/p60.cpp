//character or numeric palindrome
//number ko character ke form me strore ho jata hai
//jab inko comparare karoge to barabar numeric ki tarah compare hoga   :)

#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char a[] ){
	int i=0;
	int n= strlen(a);
	int j= n-1;
	while(i<j){
		if(a[i]==a[j]){
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



	// for(int i=0; i<n; i++){
	// 	cin>>a[i];
	// }

	if(palindrome(a)==true){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
}