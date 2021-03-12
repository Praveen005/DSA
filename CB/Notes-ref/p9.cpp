#include<iostream>
using namespace std;
int main(){

    char a[255];
   cin>>a;
    
    
    cout<<sizeof(a)<<endl<<a;
    // int n=7,maxsum=0;
    // int a[7]={5,6,4,-3,8,-6,3};
    // //we have to print all the subarrays
    // for(int i=0; i<n;i++){
    //     for(int j=0;j<n-i; j++){
    //         int p=i;
    //         int sum=0;
    //         for(int k=0; k<=j;k++){
                
    //             cout<<a[p]<<" ";
    //             sum=sum+a[k];
    //             p++;
    //         }
    //         if(maxsum<sum){
    //             maxsum=sum;
    //         }
    //         cout<<endl;
    //     }
    // }
    // cout<<"max sum oa a subarray is "<<maxsum<<endl;
}












// aliter

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[1000];
//     for(int i=0;i<n; i++){
//         cin>>a[i];
//     }
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n;j++){
//             for(int k=i; k<=j;k++){
//                 cout<<a[k]<<"  ";
//             }
//             cout<<endl;
//         }
//     }
// }