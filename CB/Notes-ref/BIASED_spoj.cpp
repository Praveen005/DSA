//problem: https://www.spoj.com/problems/BAISED/



#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define ll long long
int main() {
    ll t; cin>>t;
    
    while(t--){
        ll n; cin>>n;
        ll rank_asked[n];
        ll freq[n+1];
        memset(freq, 0, sizeof(freq));
        //we use counting sort to sort in O(N) time complexity
        for(ll i=0; i<n; i++){
            string s;
             cin>>s;
             cin>>rank_asked[i];
             freq[rank_asked[i]]++;
        }

        ll badness=0;
        ll current_rank=1;
        for(ll i=1; i<=n; i++){
            while(freq[i]){
                badness+=abs(current_rank - i);
                current_rank++;
                freq[i]--;
            }
        }
        cout<<badness<<endl;
    }
}


/*
sample input:
2

7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7

3
ThreeHeadedMonkey 1
MoscowSUx13 1
NeedForSuccess 1

sample output:
5
3

*/

