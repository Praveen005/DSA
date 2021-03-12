#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n; i++){
        cin>>a[i];
    }
    int MaxSum=0, currentSum=0,left,right;
    for(int i=0; i<n; i++){
        for(int j=i; j<n;j++){
            currentSum=0;
            for(int k=i; k<=j;k++){
              //  cout<<a[k]<<"  ";
                currentSum=currentSum+a[k];
            }
            if(MaxSum<=currentSum){
                MaxSum=currentSum; 
                left=i;
                right=j;   //updating MaxSum
            }
       //     cout<<endl;
        }
    }
    cout<<endl<<"max sum is "<<MaxSum<<endl;
    for(int p=left; p<=right;p++){
        cout<<a[p]<<" ";
    }
}