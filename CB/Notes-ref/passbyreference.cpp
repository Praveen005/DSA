#include<iostream>
using namespace std;
void increment(int *aptr){
	*aptr=*aptr+1;
    cout<<"inside increment a= "<<*aptr<<endl;
}
int main(){
	int a=10;
	increment(&a);
	cout<<"Inside main a= "<<a<<endl;
}