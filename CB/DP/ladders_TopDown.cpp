#include<iostream>
using namespace std;
int ladders_TopDown(int n, int k, int dp[]){
    //Base case
    if(n==0){
        return 1;
    }
    //lookup
    if(dp[n] != 0){
        return dp[n];
    }
    int ways=0;
    //recursive
    for(int i=1; i<=k; i++){
        if(n-i>=0){
            ways+= ladders_TopDown(n-i, k, dp);
        }
    }
    return dp[n]= ways;
}   
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n, k;
    cin>>n>>k;
    int dp[100]={0};
    cout<<ladders_TopDown(n,k,dp)<<endl;
}
