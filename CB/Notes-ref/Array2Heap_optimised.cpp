#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&v ,int index){
    int left=2*index;
    int right=left+1;

    int last=v.size()-1;
    int max_index=index;
    if(left<=last and v[left]>v[index]){
        max_index=left;
    }
    if(right<=last and v[right] > v[max_index]){
        max_index=right;
    }
    if(index != max_index){
        swap(v[max_index], v[index]);
        heapify(v, max_index);
    }

    
}
//Time complexity of this approach is O(N)
void buildHeapOptimised(vector<int>&v){
    for(int j=(v.size()-1)/2; j>=1; j--){
        heapify(v, j);
    }
    
}

int main() {
    vector<int>v{-1, 10,20,5,6,1,8,9,4};
    buildHeapOptimised(v);
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

/*

output:
-1 20 10 9 6 1 8 5 4 


*/

