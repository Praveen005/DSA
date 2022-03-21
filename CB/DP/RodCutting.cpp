#include<iostream>
#include<climits>
using namespace std;
int max_prices(int prices[], int n){
    //base case
    if(n==0){
        return 0;
    }

    //recursive case
    int ans=0;
    for(int i=0; i<n; i++){
        int current_ans= prices[i] + max_prices(prices, n-i-1);
        ans= max(current_ans, ans);
    }
    return ans;
}

//Bottom up approach
int max_profit_dp(int prices[], int n){
    int dp[100]={0};  //dp[i]:: max frofit if the length of the rod is '1'

    for(int len= 1; len<=n; len++){
        //for every lenth we need to find the optimal(max) profit
        int ans= INT_MIN;
        for(int i=0; i<len; i++){
            //'cut' means ek part ka length to fix ho gaya.
            //means for current 'length of rod' price of one part is fixed
            //now we have to derive the max profit from remaining part
            int cut= i+1;
            int current_ans= prices[i] + dp[len-cut];
            ans= max(ans, current_ans);
        }
    dp[len]=  ans; 
    }
    return dp[n];
}
int main(){
   
    int prices[]= {1,5,8,9,10,17,17,20};
    int n= sizeof(prices)/sizeof(prices[0]);
    cout<<max_prices(prices, n)<<endl;
    cout<<max_profit_dp(prices, n)<<endl;
}

