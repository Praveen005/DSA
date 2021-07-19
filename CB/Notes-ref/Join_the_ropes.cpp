#include <iostream>
#include<queue>
using namespace std;
int Join_ropes(int* ropes, int n){
    priority_queue<int, vector<int>, greater<int>>pq(ropes, ropes+n);
    int cost=0;
    while(pq.size()>1){
        int A=pq.top();
        pq.pop();
        int B=pq.top();
        pq.pop();
        cost+=(A+B);
        int cur_length=A+B;
        pq.push(cur_length);
    }
    return cost;
}
int main() {
    int ropes[]= {4,3,2,6};
    int n=4;
    cout<<Join_ropes(ropes,n)<<endl;

}


/*

output: 29

*/
