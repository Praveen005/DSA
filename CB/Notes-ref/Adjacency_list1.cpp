//simple implementation of an adjacency list
#include <iostream>
#include<list>
using namespace std;
class Graph{
    //will have how many lists would be there.
    int V;
    list<int>* l;
    public:
    //constructor
    Graph(int V){
        this->V= V;
        l= new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList(){
        //iterate all vertices
        for(int i=0; i<V; i++){
            cout<<"vertex "<<i<<"--> ";
            for(int x: l[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

};
int main() {
    Graph G(4);
    G.addEdge(0,1); //add an edge between 0 & 1
    G.addEdge(0,2);
    G.addEdge(2,3);
    G.addEdge(1,2);
    G.printAdjList();
}

