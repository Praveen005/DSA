#include <iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main() {
    int n; cin>>n;
    int whiteDots[100];
    int blackDots[100];
    for(int i=0; i<n; i++){
        cin>>whiteDots[i];
    }

    for(int i=0; i<n; i++){
        cin>>blackDots[i];
    }
    
    sort(whiteDots, whiteDots+n);
    sort(blackDots, blackDots+n);
    int sum=0;
    for(int i=0; i<n; i++){
        sum+= abs(blackDots[i]- whiteDots[i]);
    }
    cout<<sum<<endl;
}

/*

sample input:
3
3 4 1
2 5 6

sample output:
5

*/

