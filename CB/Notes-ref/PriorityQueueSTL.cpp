#include <iostream>
#include<queue>
using namespace std;
int main() {
    //By default the priority queue is a max heap 
    priority_queue<int>pq;
    //to make the priority queue behave like a min heap, do the following
    priority_queue<int, vector<int>, greater<int>>pq2;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int num; cin>>num;
        pq.push(num);
        pq2.push(num);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }

    

}

