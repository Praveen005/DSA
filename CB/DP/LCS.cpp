#include<iostream>
#include<vector>
using namespace std;
int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    
    //Base case
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    //check if the given state is already computed or not
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    // Recursive case
    if(s1[i]==s2[j]){
        //never pass i++, because it will pass 'i' and then will do i=i+1 
        // return (1+ lcs(s1, s2, i++, j++)); 

        // return (1+ lcs(s1, s2, ++i, ++j));   //you can do this
        return dp[i][j]= (1+ lcs(s1, s2, i+1, j+1, dp));
    }

    //if they are not eqaul then we have two options to explore
    int op1= lcs(s1, s2, i+1, j, dp);
    int op2= lcs(s1, s2, i, j+1, dp);
    return dp[i][j]= max(op1, op2);
}
int main(){
   
    string s1="ABCD";
    string s2= "ABEDG";
    //make a DP vector and initialize each cell with -1
    // vector contains n1 rows, each with n2 columns and every cell initialized with -1(not with 0, cz zero can be a answer incase nothing matches)
    int n1, n2;
    n1= s1.length();
    n2= s2.length();
    vector<vector<int>>dp(n1, vector<int>(n2, -1));
    cout<<lcs(s1, s2, 0, 0, dp)<<endl;

}


/*
    DP[i][j] means the max length subsequence, when pointer one is at ith position of string1
    and 2nd pointer is at jth position of string2.

    dp[0][0] is our final answer.
*/
