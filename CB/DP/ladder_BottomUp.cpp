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
int ladders_BottomUp(int n, int k){
    int dp[100]={0};
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i>=j){
                dp[i]+= dp[i-j];
            }
        }
    }
    return dp[n];
}

int ladder_optimised(int n, int k){
    int dp[100]={0};
    //Base case
    dp[0]= dp[1]= 1;
    for(int i=2; i<=k; i++){
        dp[i]= 2* dp[i-1];
    }
    for(int i=k+1; i<=n; i++){
        dp[i]= 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n, k;
    cin>>n>>k;
    int dp[100]={0};
    cout<<"Top Down Approach: "<<ladders_TopDown(n,k,dp)<<endl;
    cout<<"Bottom up Approach: "<<ladders_BottomUp(n, k)<<endl;
    cout<<"Optimized Approach: "<<ladder_optimised(n,k)<<endl;
}
