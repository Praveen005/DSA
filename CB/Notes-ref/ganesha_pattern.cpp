#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n%2!=0 && n>=5 && n<=99){
		cout<<"*";				// 1st line 
		int k1=(n-1)/2-1;
		while(k1>0){
			cout<<" ";
			k1--;
		}
		k1=(n-1)/2-1;
		int k2=(n-1)/2;
		while(k2>0){
			cout<<"*";
			k2--;
		}
		cout<<"*";					
		k2=(n-1)/2;
		cout<<endl;									////1st line*



		for(int i=1; i<= (n-3)/2 ; i++){			//2nd till mid-1
			cout<<"*";
			while(k1>0){
				cout<<" ";
				k1--;
			}
			cout<<"*";
			while(k2>0){
				cout<<" ";
				k2--;
			}
			cout<<endl;

		k2=(n-1)/2;								
		k1=(n-1)/2-1;
		}										//2nd till mid-1 *




		k2=(n-1)/2;								// value of k1 , k2 is being updated to be used further
		k1=(n-1)/2-1;


		for(int i=1; i<=n; i++){				// mid-line
			cout<<"*";
		}										
		cout<<endl;								////mid-line*


		for(int i=1; i<= (n-3)/2 ; i++){		// mid+1 to last-1
			while(k2>0){
				cout<<" ";
				k2--;
			}
			cout<<"*";
			while(k1>0){
				cout<<" ";
				k1--;
			}
			cout<<"*";
			cout<<endl;

		k2=(n-1)/2;								
		k1=(n-1)/2-1;
		}										// mid+! till last-1

		k2=(n-1)/2;								// value of k1 , k2 is being updated to be used further
		k1=(n-1)/2-1;





		while(k2>0){
			cout<<"*";
			k2--;
		}
		cout<<"*";
		k2=(n-1)/2-1;	
		while(k2>0){
			cout<<" ";
			k2--;
		}	
		cout<<"*";				

		cout<<endl;	
		break;							

	}


}