//problem: https://www.spoj.com/problems/MST/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>gr[n + 1];
    //visited means included in my MST
    int vis[n + 1] = {0};

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[x].push_back({y, w});
        gr[y].push_back({x, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;

    //{weight, node}
    Q.push({0, 1});
    long long mst = 0;
    while (!Q.empty()) {
        pair<int, int>best = Q.top();
        Q.pop();

        int weight = best.first;
        int to = best.second;

        //not an active edge
        if (vis[to]) continue;

        //otherwise add to mst and mark visited
        mst += weight;
        vis[to] = 1;

        //now that 'to' vertex is visited, mark all the non-pushed active edges to the priority queue
        for (auto x : gr[to]) { // adjacency list of 'to'
            if (vis[x.first] == 0) {
                //means x.first is not visited
                Q.push({x.second, x.first});
            }
        }
    }
    cout << mst << endl;
}


/*
sample input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

output:
17


sample input 2:
9 15
1 2 10
2 3 9
1 3 12
3 5 3
5 4 7
2 4 8
3 6 1
4 6 10
5 6 3
4 7 8
4 8 5
6 8 6
7 8 9
7 9 2
8 9 11

output:
43

*/
