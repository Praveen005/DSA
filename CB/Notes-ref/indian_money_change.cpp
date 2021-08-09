// Greedy approach to Indian money change

#include <iostream>
#include<algorithm>
using namespace std;
int make_change(int* coins, int n, int money){
    int ans=0;
    // since, the coins[] is sorted, so we will use upper_bound()
    //lower_bound : >=
    //upper_bound : strictly >
    while(money){
        //greater se just pichhe wala denomination chahiye hame
        int index= upper_bound(coins, coins+n ,money) - 1 - coins;
        money-= coins[index];
        ans++;
    }
    return ans;
}
int main() {
    int coins[]= {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n= sizeof(coins)/ sizeof(coins[0]);
    int money; cin>>money;
    cout<<"Total number of coins need is: "<<make_change(coins, n, money);

}

/*
sample input:
39

sample output:
5

*/
