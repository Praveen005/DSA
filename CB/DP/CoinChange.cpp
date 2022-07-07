#include <iostream>
#include<climits>
using namespace std;
int MinCoins_TopDown(int n, int coins[], int T, int dp[]){
    //Base case
    if(n==0){
        return 0;
    }
    //Look up if the current state is already calculated or not
    if(dp[n] != 0){
        return dp[n];
    }

    //recursive case
    int ans= INT_MAX;
    //for every value of N, we can pick maximum of T types of coins
    for(int i=0; i<T; i++){
        if(n-coins[i]>=0){
            int subprob= MinCoins_TopDown(n-coins[i], coins, T,dp);
            ans= min(ans, subprob+1);

        }
    }
    dp[n]=ans;
    return dp[n];
}

//Bottom up approach
int MinCoins_BotUP(int N, int* coins, int T){
    int dp[100]={0};

    for(int n=1; n<=N; n++){
        dp[n]= INT_MAX;
        for(int i=0; i<T; i++){
            if(n-coins[i]>=0){
                int subprob= dp[n-coins[i]];
                dp[n]= min(dp[n], subprob+1);
            }
        }
    }     
    return dp[N];
}
int main() {
    int N= 15; // sum of money
    int coins[]={1,7,10};
    //  'T' is total number of different coins
    int T= sizeof(coins)/sizeof(coins[0]);
    int dp[100]={0};
    cout<<MinCoins_TopDown(N, coins, T, dp)<<endl;
    cout<<MinCoins_BotUP(N, coins, T)<<endl;
}


//corner case:   https://ide.codingblocks.com/s/667397
