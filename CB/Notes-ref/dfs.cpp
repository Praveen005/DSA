#include <iostream>
#include<map>
#include<list>
using namespace std;

//we don't know the data type of the nodes
template<typename T>
class Graph{
    private:
    map<T, list<T>>l;

    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool>& visited){
        cout<<src<<" ";
        visited[src]= true;
        
        //l[src] is the list of all the neighbours of the source node
        for(T nbr: l[src]){
            T node= nbr;
            if(visited[node]== false){
                dfs_helper(node, visited);
            }
        }


    }

    void dfs(T src){
        //keep a map to store the status of visit 
        map<T, bool> visited;
        //initially all the nodes are non-visited
        for(pair<T, list<T>> p: l){
            T node= p.first;
            visited[node]= false;
        }

        //since the function would be a recursive one, so we need a helper function
        dfs_helper(src, visited);
    }
};
int main() {
    Graph<int> G;
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,5);
    G.dfs(0);
}


/*

(2)---------(1)
|            |
|            |
|            |
(3)---------(0)
|
|
|
(4)--------(5)

*/
