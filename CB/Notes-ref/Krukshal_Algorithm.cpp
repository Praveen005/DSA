

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class DSU{
public: 
    vector<int>parent;
    //initialize the DSU,constructor
    void init(int NN){
        parent.clear(); parent.resize(NN);
        iota(parent.begin(), parent.end(), 0);
    }
    //this one is find function
    int get(int x){
        return x== parent[x]? x : (parent[x]= get(parent[x]));
    }

    //union function

    void unite(int x, int y){
        x= get(x);
        y= get(y);
        if(x != y){
            parent[x]= y;
        }
    }
};

void solve(){
    int i, j, k, m, n, ans=0, cnt=0,sum=0;
    cin>>n>>m;
    vector<vector<int>>edges(m);
    for(int i=0; i<m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        //because the nodes are 1 based index
        //if you don't want to do this, reserve (m+1) space for the 'edges' vector
        x--;
        y--;
        //put w first, you won't need a comparator function in inbuilt sort() fnction
        edges[i]={w,x,y};
    }
    sort(edges.begin(), edges.end());

    DSU G;
    G.init(n); // initialize
    for(int i=0; i<m;i++){
        int x= edges[i][1];
        int y= edges[i][2];
        int w= edges[i][0];

        if(G.get(x) != G.get(y)){  // can take this edge, it won't form a cycle.
            G.unite(x,y);
            //include all the edges which don't result in cycle
            ans+=w;
        }
    }
    cout<<ans<<endl;
}
int main() {
    solve();
}


/*

sample input:

9 15
1 2 10
2 3 9
1 3 12
3 5 3
5 4 7
2 4 8
3 6 1
4 6 10
5 6 3
4 7 8
4 8 5
6 8 6
7 8 9
7 9 2
8 9 11


sample output:

43

*/
