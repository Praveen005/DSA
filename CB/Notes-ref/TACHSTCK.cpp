
//problem: https://www.codechef.com/problems/TACHSTCK

#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int n; cin>>n;
    int d; cin>>d;
    int arr[100005];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int res=0;
    int pointer=0;
    for(int i=1; i<n; i++){
        if(arr[i]-arr[pointer]<=d){
            i++;
            pointer+=2;
            res++;
        }
        else{
            pointer++;
        }

    }
    cout<<res<<endl;
}

