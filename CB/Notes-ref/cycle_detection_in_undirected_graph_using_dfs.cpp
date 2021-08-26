#include <iostream>
#include<list>
using namespace std;
class Graph {
private:
    int V;
    list<int>* l;

public:
    // constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = false) {
        l[x].push_back(y);
        if (!directed) {
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool* visited, int parent) {
        visited[node] = true;


        //see its neighbour to find the back edges
        for (int nbr : l[node]) {
            if (!visited[nbr]) {
                bool ans = cycle_helper(nbr, visited, node);
                if (ans) {
                    return true;
                }

            }
            //visited hai but wo parent nahi hai. means cycle is there.
            else if (nbr != parent) {
                return true;
            }
        }

        return false;
    }

    bool detect_cycle(void) {
        //visted array
        bool * visited = new bool[V] {0};

        //0 ka parent 0 hi hoga.
        int parent = 0;
        bool ans = cycle_helper(0, visited, 0);
        return ans;

    }

};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);


    if (g.detect_cycle()) {
        cout << "There is a cycle in the given Undirected Graph\n";
    }
    else {
        cout << "There is no cycle in the given Undirected Graph\n";
    }
}

