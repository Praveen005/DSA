#include<iostream>
using namespace std;
int main(){
	int a[5]={1,-2,-3,44,-5};
	int cursum=0, maxsum=0;
	for(int i=0; i<5; i++){
		cursum = cursum +a[i];
		if(cursum<0){
			cursum=0;
		}
	
		if(maxsum<=cursum){
			maxsum=cursum;
		}
   }
   cout<<maxsum<<endl;

}