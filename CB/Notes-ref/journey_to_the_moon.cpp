//problem: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
#include <iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;
#define ll long long
vector<int>v;
class Graph{
    private:
    map<int , list<int>> l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(int source, map<int, bool>&visited, int &count){
        visited[source]=true;
        count++;
        //searching for sources's neighbours
        for(int node: l[source]){
            if(!visited[node]){
                dfs_helper(node, visited, count);
            }
        }
        return;
    }
    void dfs(void){
        map<int, bool>visited;
        //initially no node is visited, set em all to false;
        for(pair<int, list<int>>p: l){
            int node= p.first;
            visited[node]= false;
        }
        for(auto p:l){
            int node= p.first;

            if(!visited[node]){
                int count=0;

                dfs_helper(node, visited, count);
                v.push_back(count);
                
            }
        }
    }

};
int main() {
    Graph G;
    int n; cin>>n;
    int k; cin>>k;
    while(k--){
        int a, b; cin>>a>>b;
        G.addEdge(a,b);
    }
    G.dfs();
    ll value= 0ll;
    //vector v stores how many people are there in each component of the graph.
    for(ll c: v){
        value+= ((ll)c*(c-1))/2;
    }
    value= ((ll)n*(n-1))/2- value;
    cout<<value<<endl;
}

