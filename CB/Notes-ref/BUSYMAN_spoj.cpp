//problem link: https://www.spoj.com/problems/BUSYMAN/


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//custom comparator function
bool compare(pair<int, int>p1, pair<int, int>p2){
    return p1.second < p2.second;
}
int main() {
    int t, n,s,e;
    cin>>t;
    vector<pair<int, int>>v;
    while(t--){
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }

        // sort as per the ending time of the events
        sort(v.begin(), v.end(), compare);

        int result=1;
        int end_time= v[0].second;
        for(int i=1; i<n; i++){
            if(v[i].first >=end_time){
                result++;
                end_time=v[i].second;
            }
        }
 
        cout<<result<<endl;
        //clear the vector for the next test case
        v.clear();
    }
}

/*
sample input:
3
3
3 9
2 8
6 9

4
1 7
5 8
7 8
1 8

6
7 9
0 10
4 5
8 9
4 10
5 7

sample output:
1
2
3
*/

