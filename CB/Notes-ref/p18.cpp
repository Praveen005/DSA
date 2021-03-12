#include<iostream>
using namespace std;
int fact(int no){
	int product=1;
	int i=1;
	while( i<=no){
		product=product*i;
		i++;
	}
	return product;
}
int main(){
	 float x;
	 cin>>x;
	 int n;
	 cin>>n;
	 int k=1;
	 long double sum=0.0,p=x*x;
	 for(int i=1; i<=n;i++){
	 	sum=sum+(x/fact(k));
	 	
	 	x=x*p;
	 	k=2*i+1;
	 	cout<<"x= "<<x<<endl<<"k= "<<k<<endl;

	 }
	 cout<<sum<<endl;


}