#include<iostream>
#include<algorithm>
using namespace std;
void twoPairSum(int *a , int index,int itr,int target){
	// index wo hai jahan se count hoga array , matlab iss array ka zeroth element
	if(index<itr){
		int newTarget=target-a[index-1];
		int l=index,m=itr-1;
		while(l<m){
			int cur_sum1=a[l]+a[m];
			if(cur_sum1==newTarget){
				cout<<a[index-1]<<" "<<a[l]<<"	"<<a[m]<<endl;
				l++;
				m--;
			}
			else if(cur_sum1>newTarget){
				m--;
			}
			else if(cur_sum1<newTarget){
				l++;
			}
		}
	}
	else return;
}
int main(){
	int itr;
	cin>>itr;
	int a[itr];
	for(int i=0; i<itr; i++){
		cin>>a[i];
	}
	int target;
	cin>>target;
	sort(a, a+itr);
	 for(int i=0;i<itr-2; i++){
	 	twoPairSum(a,i+1,itr,target);
	 }
}