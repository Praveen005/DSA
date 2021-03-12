// Generic programming

#include<iostream>
#include<list>
using namespace std;
template<class ForwardIterator , typename T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) {
    while (start != end) {
        if (*start == key) {
            return start;
        }
        start++;
    }
    return end;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    list<int>::iterator it = search(l.begin(), l.end(), 33);
    cout << *it << endl;

}