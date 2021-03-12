#include<iostream>
#include<cstring>
using namespace std;
void rotate(char *a , int k){ 						// you can also use a[]  || a[100] || *a     : all these three notations are correct
	int i= strlen(a);								// don't use a.length(), because it is used for a string 's' and not an array. 
	int j=i;
	while(j>=0){
		a[j+k]= a[j];
		j--;
	}
	int s=0,q=i;

	for( ; s<k; s++){
		a[s]=a[q];
		q++;
	}
	a[i]='\0';
}
int main(){
	char a[100];
	cin.get(a,100);
	int k;
	cin>>k;
	
	rotate(a,k);
	cout<<a<<endl;

}