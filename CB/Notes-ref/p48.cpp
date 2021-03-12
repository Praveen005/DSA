#include<iostream>
using namespace std;


bool compare(int a, int b){

		return a>b;
	
	}



int main(){
	
	int prev,next;
	int n;
	cin>>n;
	cin>>prev;
		if (n==1)
		{
			cout<<"true"<<endl;
		}
	int count =0,count1=0, count3=0;
	int l=n-1;


	while(l>0 ){
		int k=n-1;
		cin>>next;
		if(prev==next){
			break;
		}

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
			if(l>=n-2){
				count3++;
			}	
		}
		l--;
	}






	if((count==0 && count1==0)){
		cout<<"false"<<endl;
	}
	else{
	if((count!=0 && count1==0 ) ||  (count1!=0 && count==0)){
		cout<<"true"<<endl;
	}
	else if(count1==count && count3 !=0){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
}
}