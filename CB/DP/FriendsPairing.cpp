#include <iostream>
using namespace std;
int FriendsPairing(int n, int dp[]){
    //Base case
    if(n==0 || n==1){
        return 1;
    }
    //check if the value is already computed
    if(dp[n]){
        return dp[n];
    }
    return  dp[n]= FriendsPairing(n-1, dp) + (n-1)*FriendsPairing(n-2, dp);
}
int main() {
    int n; cin>>n;
    int dp[1000]={0};
    cout<<FriendsPairing(n, dp);
}

