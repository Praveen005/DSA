#include<iostream>
using namespace std;
//previously it was max 500  but utne pe runtime  error de raha tha
//matlab pura compute hone se pahle array ka size chhota pad gaya
//so i increased it to 5000 :)
#define MAX 5000

int multiply(int a[] , int array_size  ,int i){

    int product;
    int carry=0;
    for(int j=0 ; j<array_size; j++){
        product = a[j]*i + carry;
       
        a[j]=product%10;
        carry=product/10;
    }
    while(carry){
        a[array_size]=carry%10;
        array_size++;
        carry=carry/10;
    }
    return array_size;

}


void factorial( int n){
    int a[MAX];
    a[0]=1;
    int array_size=1;
    

    for(int i=2; i<=n; i++){
        //here we need to multiply array to each  i  and form an updated array;
       array_size=multiply(a ,array_size, i);
    }

    for(int i=(array_size-1); i>=0; i--){
        cout<<a[i];
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    factorial(n);
}