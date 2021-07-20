/*

merge k given sorted arrays


*/


//you can use custom class/ pair

//using custom class
//when using custom class we also need to use a comparator class.
//can't use, greater<class_name> for min heap

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//for every element, we need three informations,
// 1. value
//2. in which array it is 
//3. its index in that particular array
class node {
public:
    int value;
    int array_index;
    int element_index;

    //constructor
    node() {

    }

    node(int v, int a, int i) {
        value = v;
        array_index = a;
        element_index = i;
    }
};

class nodeCompare {
public:
    bool operator()(node A, node B) {
        return A.value > B.value;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> v) {
    vector<int>result;
    //make the min heap
    priority_queue<node, vector<node>, nodeCompare>pq;

    //v.size() gives us the number of arrays/vectors inside the vector
    for (int i = 0; i < v.size(); i++) {

        // node n(v[i][0], i, 0);
        node n;
        n.value = v[i][0];
        n.array_index = i;
        n.element_index = 0;
        pq.push(n);
    }

    while (!pq.empty()) {
        node temp = pq.top();
        pq.pop();
        result.push_back(temp.value);
        int y = temp.element_index;
        if (y + 1 < v[temp.array_index].size()) {
            temp.value = v[temp.array_index][y + 1];
            // temp.array_index=array_index;
            temp.element_index = y + 1;
            pq.push(temp);

        }

    }
    return result;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>v = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9},
        {10, 11, 12, 13, 14, 15, 16}
    };

    vector<int>output = mergeKSortedArrays(v);

    for (int x : output) {
        cout << x << " ";
    }
    cout << endl;
}

*/




//using Pair STL



#include <iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> v){
    vector<int>result;
    //make the min heap
    priority_queue<node, vector<node>, greater<node>>pq;

    //v.size() gives us the number of arrays/vectors inside the vector
    for(int i=0; i<v.size(); i++){
        //we can initialize 'n' the following way, says c++11
        node n({v[i][0], {i, 0}});
        pq.push(n);

        //can directly push as well
        // pq.push({v[i][0], {i, 0}});
    }

    while(!pq.empty()){
        node current= pq.top();
        pq.pop();
        int element=current.first;
        int x= current.second.first;
        int y=current.second.second;
        result.push_back(element);

        if(y+1<v[x].size()){
            pq.push({v[x][y+1], {x, y+1}});

        }
        
    }
    return result;
}
int main() {
    vector<vector<int>>v={
        {1,2,3,4,95},
        {6,7,8,9},
        {-109,11,12,13,14,15,196}
    };

    vector<int>output= mergeKSortedArrays(v);

    for(int x:output){
        cout<<x<<" ";
    }
    cout<<endl;
}


/*

OUTPUT:
-109 1 2 3 4 6 7 8 9 11 12 13 14 15 95 196

*/

