#include<iostream>
#include<climits>
#include<list>
#include<map>
using namespace std;
#define ll long long

#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

template<typename T>
class Graph {
private:
    map<T, list<T>>l;

public:
    void addEdge(T x, T y) {
        l[x].push_back(y);
        // l[y].push_back(x);
    }
    void dfs_helper(T source, map<T, bool>&visited, list<T>& ordering) {
        visited[source] = true;

        //Now we will search for the neighbours of the source node.
        for (T nbr : l[source]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(source);
        return;
    }

    //taking no argument because if we choose any one the non-visited node of a component,
    //it will traverse all the nodes and getting our job done.
    void dfs(void) {
        map<T, bool>visited;
        list<T>ordering;
        //initially all node are non-visited
        for (pair<T, list<T>> P : l) {
            T node = P.first;
            visited[node] = false;
        }
        /*
            when we call the dfs fucntion for the first time,
            the 'dataset' item won't get visited because it has no dependency.
            This is why we need the following for loop to check for each node if it has been visited or not
            and accordingly call the dfs_helper() again.
        */
        for (auto p : l) {
            T node = p.first;
            if (!visited[node]) {
                dfs_helper(node, visited, ordering);
            }
        }


        //finally print the list
        for (T node : ordering) {
            cout << node << "\n";
        }
    }
};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    Graph<string>g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecognition");
    g.addEdge("DataSet", "FaceRecognition");
    g.dfs();




}





