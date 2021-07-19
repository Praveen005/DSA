#include <iostream>
#include<vector>
using namespace std;
//false: max heap ; true : min heap
bool minHeap = false; 
bool compare(int a, int b){
    if(minHeap){
        return a<b;
    }
    return a>b;
}
void heapify(vector<int>&v, int index, int size){
    int last=size;
    int left=2*index;
    int right=left+1;
    
    int max_index=index;

    if(left<=last and compare( v[left], v[index])){
        max_index=left;
    }


    if(right<= last and compare(v[right], v[max_index])){
        max_index=right;
    }

    if(index != max_index){
        swap(v[index], v[max_index]);
        heapify(v, max_index, size);
    }
}
void buildHeap(vector<int>&v){
    int n=v.size()-1;
    for(int j=n/2; j>=1; j--){
        heapify(v,j,n);
    }
}

void heapsort(vector<int>&v){
    int n=v.size()-1;
    while(n>1){
        swap(v[1], v[n]);
        n--;
        heapify(v, 1, n);
        
    }
}

int main() {
    //complexity of heapsort is O(NlogN)
    vector<int>v{-1,6,1,8,9,4};
    buildHeap(v);
    
    heapsort(v);
    cout<<"Sorted Array:\n";
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;

}

