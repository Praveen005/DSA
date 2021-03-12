#include<iostream>
#include<climits>
using namespace std;
int max_num(int a[], int n){
	int max=INT_MIN;
	for(int i=0; i<n; i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int main(){
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<max_num(a,n)<<endl;

}