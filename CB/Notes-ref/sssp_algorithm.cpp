
//single source shortest path algorithm

#include <iostream>
#include<map>
#include<list>
#include<climits>
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
    //Distance traversed by BFS is shortest if the graph is un-weighted
    void bfs(T src){
        //following map will keep track of the distance of a node from the source node
        map<T, int>distance;
        T node= src; //src: source node
        queue<T>q;
        q.push(src);
        //initially we will keep the distance of each node from source = infinite
        for(pair<T, list<T>> node:l){
            T x= node.first;
            distance[x]=INT_MAX;
        }
        //distance for source node will be zero.
        distance[src]= 0;
        while( !q.empty()){
            
            T temp= q.front();
            cout<<temp<<" ";
            q.pop();
            
            //l[temp] will give all the neighbours 
            //we will push all its neighbours to the queue
            for(T nbr: l[temp]){
                if(distance[nbr]==INT_MAX){   //means still not visited
                    q.push(nbr);
                    //updating the distance of the visited node
                    distance[nbr]=distance[temp]+1;
                }
            }            
        }
        //print the distance of a node from the source.
    cout<<endl;
    for(pair<T, list<T>> p: l){
        T node= p.first;
        cout<<"Distance of node "<<node<<" from source is "<<distance[node]<<endl;
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
    cout<<"BFS/Level Order Traversal--> ";
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
(4)--------(5)

*/
