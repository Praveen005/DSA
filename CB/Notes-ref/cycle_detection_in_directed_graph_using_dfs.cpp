#include <iostream>
#include<list>
using namespace std;
class Graph{
    private:
    int V;
    list<int>* l;

    public:
    // constructor
    Graph(int V){
        this->V= V;
        l= new list<int>[V];
    }

    void addEdge(int x, int y, bool directed= true){
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);            
        }
    }

    bool cycle_helper(int node, bool* visited, bool* stack){
        visited[node]= true;
        stack[node]= true;

        //see its neighbour to find the back edges
        for(int nbr: l[node]){
            if(!visited[nbr]){
                bool ans= cycle_helper(nbr, visited, stack);
                if(ans){
                    return true;
                }
                
            }
            else if(stack[nbr]){
                return true;
            }
        }
        //empty the stach when leaving/ returning from the node.
        stack[node]= false;
        return false;
    }

    bool detect_cycle(void){
        //visted array
        bool * visited= new bool[V]{0};
        //array to keep track if a node is present in the stack or not.
        bool* stack= new bool[V]{0};

        bool ans= cycle_helper(0, visited, stack);
        return ans;

    }

};

int main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2);  //Back edge
    if(g.detect_cycle()){
        cout<<"There is a cycle in the Graph\n";
    }
    else{
        cout<<"There is no cycle in the Graph\n";
    }
}

