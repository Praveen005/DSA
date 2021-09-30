#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

#define INF 10000

vector<vector<int>> floys_warshall( vector<vector<int>>&graph) {
    vector<vector<int>> dist(graph);
    int V = graph.size();

    //phase: in kth phase we include {1,2,3,.. k} vertices as the intermediate vertex

    //we have V phases so we'll run the loop V times
    for (int k = 0; k < V; k++) {
        //iterate over the entire 2-D matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // if K is an intermediate vertex, can we minimize the distance or not? let's see
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

                //if you don't define infinity then you can use the following
                // if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX and dist[i][j] > dist[i][k] + dist[k][j]) {
                //     dist[i][j] = dist[i][k] + dist[k][j];
                // }
            }
        }
    }

    //CHECKING THE NEGATIVE WEIGHT CYCLE
    //if any of the diagonal element has any -ve value then it has a -ve cycle.
    //you would have obseved that the value of the source node changes in case of -ve weight cycle.
    //Distance of any node from itself is always zero.we just have to check the nodes distance from itself and if it comes out to be negative,
    //we will detect the required negative cycle.

    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle found\n";
            exit(0);
        }
    }


    return dist;
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CINT
    //4 Vertices and 4x4 matrix
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };

	//-ve weight cycle.
    // vector<vector<int>>graph = {
    //     {0   , 1   , INF , INF},
    //     {INF , 0   , -1  , INF},
    //     {INF , INF , 0   ,  -1},
    //     { -1  , INF , INF ,   0}
    // };

    auto result = floys_warshall(graph);
    //printing the resultant distance matrix
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

