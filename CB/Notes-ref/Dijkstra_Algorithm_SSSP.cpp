
//We will print the shortest path as well

#include<iostream>
#include<climits>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;
#define ll long long

#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);


template<typename T>
class Graph {
private:
    unordered_map<T, list<pair<T, int>>>m;
    unordered_map<T, T> parent;


public:

    void addEdge(T u, T v, int dist, bool Bidirectional = true) {
        m[u].push_back(make_pair ( v, dist));

        if (Bidirectional) {
            m[v].push_back(make_pair (u, dist));
        }
    }


    //we need sth to store and keep track of the distance of a node from source
    //we;ll use hashmap
    void DijkstraSSSP(T src) {
        unordered_map<T, int> dist;
        //initially the distance of all nodes from the source = infinite
        //for source it wd be 0;
        for (auto p : m ) {
            T node = p.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        //Parent of source node will be the source node itself
        parent[src] = src;


        //make a set to find out the node with minimum distance
        //Set me  default SORTING pair ke 1st element ke according hoti hai
        //it will always give the node with mn distance
        set<pair<int, T>> s;
        s.insert(make_pair(dist[src], src));
        while (!s.empty()) {

            //find a pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());


            //update the distance of the neighbouring nodes of the current node
            for (auto childPair : m[node]) {
                T nbr = childPair.first;
                //weight(distance here) of the edge between the parent node
                //and the neighbour
                int weight = childPair.second;

                if (nodeDist + weight < dist[nbr]) {

                    //in set updation of a value is not possible, so we first revove it and then
                    //insert the updated value again.
                    //first search if the node is present in the set
                    auto ind = s.find(make_pair(dist[nbr], nbr));

                    //its possible ki ye kisi aur ka bhi neighbour ho aur iska value pahle hi infinity se change/update ho
                    //gaya ho.
                    //if the distance of this node from the current path is less than the previous updated value.
                    //we will update its distance from source again.
                    if (ind != s.end()) {
                        s.erase(ind);
                    }
                    dist[nbr] = nodeDist + weight;
                    parent[nbr] = node;
                    s.insert(make_pair(dist[nbr], nbr));

                }
            }
        }

        for (auto p : m) {
            T node = p.first;
            cout << "shortest distance of " << node << " from " << src << " is ";
            cout << dist[node] << endl;
        }

    }

    void printAdj() {

        for (pair<T, list<pair<T, int>>> p : m) {
            T node = p.first;
            cout << node << "--> ";
            for (pair<T, int> p1 : m[node]) {
                cout << "(" << p1.first << "," << p1.second << ") ";
            }
            cout << "\n";
        }
    }


    // printing the shortest path
    void PrintPath(T src, T node) {
        if (node == src) {
            cout << src;
            return;
        }
        cout << node << " <- ";
        PrintPath(src, parent[node]);

    }

};






int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT


    // Graph<int> g;
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 2);
    // g.addEdge(1, 4, 7);
    // // g.printAdj();
    // g.DijkstraSSSP(1);



    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Jaipur", "Delhi", 2);
    india.addEdge("Jaipur", "Mumbai", 8);
    india.addEdge("Bhopal", "Agra", 2);
    india.addEdge("Mumbai", "Bhopal", 3);
    india.addEdge("Agra", "Delhi", 1);
    // india.printAdj();
    india.DijkstraSSSP("Amritsar");
    
    india.PrintPath("Amritsar", "Bhopal");
    cout << endl;
    india.PrintPath("Amritsar", "Mumbai");
    cout << endl;
    india.PrintPath("Amritsar", "Jaipur");

}
