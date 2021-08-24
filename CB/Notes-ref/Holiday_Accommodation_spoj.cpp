

//problem:  https://www.spoj.com/problems/HOLI/


#include <iostream>
#include<list>
using namespace std;
#define ll long long
class Graph {
private:
    int V;
    list<pair<int, int>>* l;

public:
    //constructor
    Graph(int V) {
        this->V = V;
        //l is an array of list of neighbours of a node with its weight.
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int x, int y, int wt) {
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    int dfs_helper(int src, bool* visited, int* count, ll& ans) {
        visited[src] = true;
        count[src] = 1;
        //search for all the neighbours of src
        for (pair<int, int> p : l[src]) {
            int wt = p.second;
            int nbr = p.first;
            if (!visited[nbr]) {
                count[src] += dfs_helper(nbr, visited, count, ans);
                int child_count = count[nbr];
                int lc = V - child_count;
                ans += 2ll * wt * (ll)min(lc, child_count);

                dfs_helper(nbr, visited, count, ans);
            }
        }
        return count[src];
    }
    ll dfs() {
        //keep an array of bools
        bool* visited = new bool[V];
        int* count = new int[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            count[i] = 0;
        }
        ll ans = 0ll;
        dfs_helper(0, visited, count, ans);
        return (ll)ans;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t;
    int n, x, y, wt;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        Graph g(n);
        for (int i = 1; i < n; i++) {
            cin >> x >> y >> wt;
            g.addEdge(x - 1, y - 1, wt);
        }

        ll ans = g.dfs();
        cout << "Case #" << i << ": " << ans << endl;

    }


}

