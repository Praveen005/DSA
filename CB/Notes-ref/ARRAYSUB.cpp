#include <iostream>
#include<deque>
using namespace std;
int main() {
    int n;
    int a[1000002];
    int k;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>k;
    deque<int> q(k);  // deque initialized with size k

    /* We always store index of max value of a window in the deque or of the value which is 
    presumed to be max ri8 now. If any bigger number is encountered later for the same window 
    then it is popped out */

    // We will now process the first k elements
    int i=0;
    for(; i<k; i++){
        while(!q.empty() and a[i]>= a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    //Remember deque stores the indices here

    //Now we will process the rest n-k elements

    for(; i<n; i++){
        //0. Print the element at the front of the deque
        // It is actually the highest value of the previous window
        cout<<a[q.front()]<<" ";


        //1. Remove all the elements that are to the left side of the chosen window
        // There are of no value.
        while(!q.empty() and q.front()<= i-k){
            q.pop_front();
        }

        //2. Remove all the elements that are in the window but are smaller than the current element
        while(!q.empty() and a[i]>=a[q.back()]){
            q.pop_back();
        }

        //3. Add the new element

        q.push_back(i);

    }
    cout<<a[q.front()];

}

