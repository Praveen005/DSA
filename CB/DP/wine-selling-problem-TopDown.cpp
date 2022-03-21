#include <iostream>
using namespace std;
//y: year, i:starting index, j: last index
int maxProfit(int wines[], int i, int j, int y, int dp[][100]){
    //base case
    if(i>j){
        return 0;
    }
    // check if the max profit from the sell of bottles priced from
    //wines[i] to wines[j] has been calculated or not
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    //recursive case
    //you can either sell the first bottle or the last bottle in the current year
    int op1= wines[i]*y + maxProfit(wines, i+1, j, y+1, dp);
    int op2= wines[j]*y + maxProfit(wines, i, j-1, y+1, dp);
    return dp[i][j]= max(op1, op2);
 }
int main() {
    int wines[]={2,3,5,1,4};
    // int wines[]={2,4,6,2,5};
    int n= sizeof(wines)/sizeof(wines[0]);
    int dp[100][100]={0};
    //Greedy gives you --> 49,  DP --> 50
    cout<<maxProfit(wines, 0, n-1, 1, dp)<<endl;
}

//Dp[i][j] : what is the optimal answer when you have bottles from 'i' to 'j'

