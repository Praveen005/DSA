#include<iostream>
#include<climits>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0; i<n; i++){
		cin>> a[i];

	}
	int min= INT_MAX,max= INT_MIN;
	for(int i=0; i<n; i++){
		if(min>a[i]){
			min=a[i];
		}
		if(max<a[i]){
			max=a[i];
		}
	}
	cout<<endl<<"max = "<<max<<endl<<"min = "<<min<<endl;

}