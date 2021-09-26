#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> bellman_ford_algo(int V, int src, vector<vector<int>>&edges_list) {
    vector<int>dist(V + 1);
    //initially the distance of every node from the source vertex would be INT_MAX
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    //relaxation
    int u, v, wt;
    for (int i = 0; i < v - 1; i++) {
        for (auto edges : edges_list ) {
            u = edges[0];
            v = edges[1];
            wt = edges[2];

            //dist[u]== INT_MAX then, INT_MAX + wt will overflow and become a -ve value;
            //it is very much possible that wt is -ve but won't affect the result.
            if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    //check for the -ve weight cycle
    for (auto edges : edges_list) {
        u = edges[0];
        v = edges[1];
        wt = edges[2];

        //if it is not a -ve weight cycle then the values of min. distances in the 'dist' vector won't change
        if (dist[u] != INT_MAX and dist[u] + wt < dist[v] ) {
            cout << "It is a negative weight cycle.\n";
            exit(0);
        }
    }
    return dist;
}


int main() {

    int n, m; cin >> n >> m; //n- vertices and m- edges

    //will contain the edge list {a, b, weight}
    vector<vector<int>>edges;

    for (int i = 0; i < m; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({a, b, wt});
    }

    vector<int> distances = bellman_ford_algo(n, 1, edges);

    //printing the distances of all the nodes from the source vertex
    for (int i = 1; i <= n; i++) {
        cout << "Distance of node " << i << " from 1 is " << distances[i] << endl;
    }


    return 0;
}


/*

input:
3 3
1 2 3
2 3 4
1 3 -10

output:
Distance of node 1 from 1 is 0
Distance of node 2 from 1 is 3
Distance of node 3 from 1 is -10


input:
3 3
1 2 3
2 3 4
3 1 -10

output:
It is a negative weight cycle.

*/
