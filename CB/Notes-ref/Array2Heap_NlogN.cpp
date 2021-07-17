/*

Given an array(vector) convert it into a heap, inplace

*/


#include <iostream>
#include<vector>
using namespace std;
void build(vector<int>&v){
    for(int i=2; i<v.size(); i++){
        int index=i;
        int parent=index/2;
        while(index > 1 and v[index]>v[parent]){
            swap(v[index], v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
}
int main() {
    vector<int>v{-1, 4,1,3,7,8,17,2,9,10};
    build(v);
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

