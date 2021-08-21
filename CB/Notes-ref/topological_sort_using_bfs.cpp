#include<iostream>
#include<climits>
#include<list>
#include<map>
#include<queue>
using namespace std;
#define ll long long

#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

class Graph {
private:
    list<int>* l;
    //number of vertices
    int V;
public:
    //constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        //since it a directed graph
        l[x].push_back(y);
    }

    void topological_sort(void) {
        int* indegree = new int[V];
        // initially make the indegree of all the nodes = 0
        for (int i = 0; i < V; i++) {
            indegree[i] = 0;
        }

        //finding indegree
        //if there is an edge x->y, then indegree[y]++;
        for (int i = 0; i < V; i++) {
            for (int y : l[i]) {
                indegree[y]++;
            }
        }



        //bfs

        //finding the nodes=0 and pushing them to the queue;
        queue<int>q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }


        //popping the node and updating the indegree of its neighbours
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            //iterate over the neighbours of the node, just popped and
            //reduce their indegree;
            for (auto nbr : l[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

    }
};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT

    Graph g(6);

    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.topological_sort();


}





