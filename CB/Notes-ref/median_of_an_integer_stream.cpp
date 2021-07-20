#include <iostream>
#include<queue>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //form max and min heap
    priority_queue<int>leftHeap; //Max heap
    priority_queue<int, vector<int>, greater<int>>rightHeap; //Min heap
    int d; cin >> d;
    leftHeap.push(d);
    float med = d;
    //print 1st median
    cout << "Median: " << med << endl;
    //input all the datas
    cin >> d;
    while (d != -1) {
        //logic
        //size of the left heap is more
        if (leftHeap.size() > rightHeap.size()) {
            if (d < med) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else {
                rightHeap.push(d);
            }
            //now we have sizes of both the heaps equal, so median = average of the their top()
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if (leftHeap.size() == rightHeap.size()) {
            if (d < med) {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }
        //size of right heap is more
        else {
            if (d > med) {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else {
                leftHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;

        }

        cout << "median: " << med << endl;
        cin >> d;
    }

}

/*

sample input:
1 1 5 4 3 0 0 8 9 10 11 -1

sample output:
Median:
-->1
-->1
-->1
-->2.5
-->3
-->2
-->1
-->2
-->3
-->3.5
-->4

*/

