//longest string
//my approach

//ek baat jaante ho ?  nahi?  :)
// remember pichhla approach  :  agr wahan do string same length ka hota to , that would have printed only the first largest string it got 
// and none of other strings of same length.

#include<iostream>
#include<cstring>
using namespace std;


int main(){
	int n;
	cin>>n;
	cin.get();
	int largest=0;
	int index;
	int a[100]={0};
	

	char s[1000][1000]={0};
	for(int i=0 ; i<n ; i++){
		
		cin.getline(s[i] , 1000);
		
		
		
	}
	for(int i=0 ; i<n ; i++){
		
		//cout<<s[i]<<endl;
	//	cout<<"strlen ["<<i<<"]"<<strlen(s[i])<<endl;
		if(strlen(s[i])>=largest){

			largest=strlen(s[i]);

			// iss while loop se ye hoga ki jitne bhi string same length ke honge wo
			// sab store honge aur phir hum use print kar denge.
			while(strlen(s[i])==largest){
				a[index]=i;
				index++;
				break;
			}
			
		
		}
	}
	cout<<endl<<endl<<"strings with largest length is/are : "<<endl;
	for(int i=0; i<index; i++){
		

		cout<<s[a[i]]<<endl;
	}

}
