/*

we get, 

[ {fib(n)}, {fib(n-1)} ](2x1 matrix)= [ {1,1}, {1,0} ]^(n-1) (2x2 matrix)* [ {fib(1)}, {fib(0)} ](2x1 matrix)

*/


#include <iostream>
using namespace std;
const int M= 2;
int fibBoUp(int n){
    int dp[100]={0};
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]= dp[i-1]+ dp[i-2];
    }
    return dp[n];
}


void mul(int res[][M], int A[][M]){
    int a, b, c, d;
    a= res[0][0];
    b= res[0][1];
    c= res[1][0];
    d= res[1][1];

    int e, f, g, h;

    e= A[0][0];
    f= A[0][1];
    g= A[1][0];
    h= A[1][1];

    res[0][0]= a*e + b*g;
    res[0][1]= a*f + b*h;
    res[1][0]= c*e + d*g;
    res[1][1]= c*f + d*h;

}
//Squaring the matrix 'A'
void square(int res[][M]){
    int a, b, c, d;
    a= res[0][0];
    b= res[0][1];
    c= res[1][0];
    d= res[1][1];
    
    res[0][0]= a*a + b*c;
    res[0][1]= a*b + b*d;
    res[1][0]= a*c + d*c;
    res[1][1]= b*c + d*d;
}
int func(int n, int A[][M]){
    int res[][M]={{1,0},{0,1}};
    int p= n-1;

    if(n==0){
        return 0;
    }

    while(p){
        if(p&1){
            mul(res,A);
        }
        p>>=1;
        square(A);

    }

    return res[0][0];
}
int main() {
    int n; cin>>n;
    cout<<"Bottom UP Approach gives: ";
    cout<<fibBoUp(n)<<endl;
    int A[M][M]={{1,1},{1,0}};
    cout<<"Using MATRIX MULTIPLICATION, we get: ";
    cout<<func(n, A);
}

/*

Here in this approach we did nothing much.
we implemented Binary exponentiation for [A]^(n-1). 
Only difference is that we are having a matrix instead instead of a number

To understand more about the approach, watch this:  
    https://www.youtube.com/watch?v=EEb6JP3NXBI&ab_channel=GauravSen
*/

