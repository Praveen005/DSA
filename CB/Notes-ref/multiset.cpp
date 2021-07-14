#include <iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator It;

class comapre{
    public:
    //overload the operator (round bracket)
    
    bool operator()(pair<string, int>a, pair<string, int>b){
        return a.second<b.second;
    }
};

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



    pair<string, int>p1= make_pair("A", 120);
    pair<string, int>p2= make_pair("B", 12);
    pair<string, int>p3= make_pair("C", 130);
    pair<string, int>p4= make_pair("D", 140);
    pair<string, int>p5= make_pair("E", 150);
    pair<string, int>p6= make_pair("F", 20);
    pair<string, int>p7= make_pair("G", 52);

    multiset<pair<string, int>, comapre>m2;
    m2.insert(p1);
    m2.insert(p2);
    m2.insert(p3);
    m2.insert(p4);
    m2.insert(p5);
    m2.insert(p6);
    m2.insert(p7);

    for(auto K : m2){
        cout<<K.first<<"  --  "<<K.second<<endl;
    }
    




    // learn more: https://www.cplusplus.com/reference/set/multiset/
}



