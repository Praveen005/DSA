#include<iostream>
#include<climits>
using namespace std;
int maxSum(int arr[], int n){
    
    int dp[100]={0};
    dp[0]= arr[0]>0? arr[0]: 0;
    int max_so_far= dp[0];
    //for array conataining all the negative elemets
    int max_element= INT_MIN;
    max_element= max(max_element, arr[0]);
    for(int i=1; i<n; i++){
        max_element= max(max_element, arr[i]);
        dp[i]= dp[i-1]+arr[i];
        if(dp[i]<0){
            dp[i]=0;
        }
        max_so_far= max(max_so_far, dp[i]);
    }
    
    if(max_so_far==0){
        return max_element;
    }
    return max_so_far;
}


int maxSumSpaceOptimized(int arr[], int n){
    
    int cur_sum=0;
    int max_so_far=0;
    //for array conataining all the negative elemets
    int max_element= INT_MIN;
    for(int i=0; i<n; i++){
        max_element= max(max_element, arr[i]);
        cur_sum+= arr[i];
        if(cur_sum<0){
            cur_sum=0;
        }
        max_so_far= max(cur_sum, max_so_far);
    }
    if(max_so_far==0){
        return max_element;
    }
    return max_so_far;
}
int main(){
    // int arr[]={-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    // int arr[]={-43, -21, -11, -5};
    int arr[]= {23, 12, 54, -65, 12, -43, -32, 10, 42};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr, n)<<endl;
    cout<<maxSumSpaceOptimized(arr, n)<<endl;
}


/*
*******one cornor case::

if all the members of the array are negative, then
max_so_far would be zero.

Think, Max_so_far would be zero only if all the elements are -ve otherwise it will be the sum of 
atleast one +ve number.

so, if max_so_far is zero then keep a variable to store the largest among all 
the negative numbers and return this instead.
*/
