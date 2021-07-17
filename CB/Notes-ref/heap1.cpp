#include <iostream>
#include<vector>
using namespace std;

class Heap {
private:
    vector<int>v;
    //This boolean will keep track of ,if the given heap is min/max;
    bool minHeap;

    bool compare(int a, int b) {
        if (minHeap) {
            return a < b;
        }
        return a > b;
    }

    void heapify(int idx) {

        int left = 2 * idx;
        int right = left + 1;
        //now we need to compare the element at index: idx with its left and right child
        //we need to check if the left and/or right child exist

        int min_idx = idx;
        int last = v.size() - 1;
        if (left <= last and compare(v[left], v[idx])) {
            min_idx = left;
        }
        if (right <= last and compare(v[right], v[min_idx])) {
            min_idx = right;
        }

        if (idx != min_idx) {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }
public:
    //constructor with some default values
    //'true' means the given heap is a minHeap
    Heap(int default_size = 20, bool type = true) {
        v.reserve(default_size);
        //we reserve the 1st node, indexing is done from 1
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d) {
        v.push_back(d);
        int index = v.size() - 1;
        int parent = index / 2;
        //keep swapping till the top or till it satisfies the heap order property i.e.
        //parent element < children (in min heap)
        while (index > 1 and compare(v[index], v[parent])) {
            swap(v[parent], v[index]);
            index = parent;
            parent /= 2;
        }
    }

    int top() {
        return v[1];
    }

    void pop() {
        //swap the 1st and the last element
        int last = v.size() - 1;
        swap(v[1], v[last]);
        //now pop_back : this deletes the root node
        v.pop_back();
        //now heapify

        heapify(1);

    }

    bool empty() {
        return v.size() == 1;
    }

};

int main() {

/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

*/

    //Max Heap
    Heap H(100, false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {

        int d; cin >> d;
        H.push(d);
    }


    while (!H.empty()) {
        cout << H.top() << " ";
        H.pop();
    }
    cout << endl;



    cout << "Min heap:\n";
    Heap H2;   // or  Heap H2(any size, true);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int data; cin >> data;
        H2.push(data);
    }

    while (!H2.empty()) {
        cout << H2.top() << " ";
        H2.pop();
    }
    cout << endl;

}

