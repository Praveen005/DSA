#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    private:
    //key of type T, ex: 2 is connected with [3,4,5] => map<2, [3,4,5]>
    map<T , list<T>>l;

    public:
    //let's keep it non-weighted  :)
    //let's take em all bi-directional
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        //let's map the nodes with if visited or not.
        map<T, int>visited;
        T node= src; //src: source node
        queue<T>q;
        q.push(src);
        visited[src]= true;
        while( !q.empty()){
            
            T temp= q.front();
            cout<<temp<<" ";
            q.pop();
            
            //l[temp] will give all the neighbours 
            //we will push all its neighbours to the queue
            for(T nbr: l[temp]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }            
        }
    }
};
int main() {
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
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
(4)---------(5)

*/
