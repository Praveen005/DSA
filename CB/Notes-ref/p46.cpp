#include<iostream>
using namespace std;
bool compare(int a, int b){
		return a>b;
	}

int main(){
	
	int prev,next;
	int n;
	cin>>n;
//	while(n>0 && n<1000){

	cin>>prev;
	// if(prev<0 ||prev>=1000000000){
	// 		break;
	// 	}
		if (n==1)
		{
			cout<<"true"<<endl;
			/* code */
		}
	int count =0;
	int count1=0;


	while(n-1>0 ){
		
		cin>>next;
		if(next<0 ||next>=1000000000){
			break;
		}
		if(compare(next, prev)==true){
			prev=next;
			count1++;
			
		}
		else if (compare(next, prev)==false){
			prev=next;
			count++;
			
		}
		n--;
	}
	if((count!=0 && count1==0) ||  (count1!=0 && count==0)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}

//break;
}

	

