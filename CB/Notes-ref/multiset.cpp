#include <iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator It;

int main() {
    int arr[]={1,2,5,2,9,3,4,2,4,5,6,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    multiset<int>m(arr, arr+n);

    //print
    for(int x: m){
        cout<<x<<" ";
    }
    cout<<endl;

    //erase all occurances of a particular element
    m.erase(2);

    for(int x: m){
        cout<<x<<" ";
    }
    cout<<endl;

    //insert element
    m.insert(8);

    for(int x: m){
        cout<<x<<" ";
    }
    cout<<endl;


    //count the number of occurances of an element

    cout<<"count of 5: "<<m.count(5)<<endl;


    //get an iterator to a particular element
    //gives me the first element that is 5

    auto it = m.find(5);
    cout<<*it<<endl;

    //get all the elemets equal to 5
    //returns a pair of iterator

    pair<It, It> range= m.equal_range(5);

    for(auto it=range.first ; it != range.second; it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    // /lower and upper bound function
    //lower_bound gives >=  : upper_bound gives strictly >
    for(auto it= m.lower_bound(2); it != m.upper_bound(9); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    // learn more: https://www.cplusplus.com/reference/set/multiset/
}


/*

output:
1 2 2 2 3 4 4 5 5 5 5 6 9 
1 3 4 4 5 5 5 5 6 9 
1 3 4 4 5 5 5 5 6 8 9 
count of 5: 4
5
5 5 5 5 
3 4 4 5 5 5 5 6 8 9 

*/
