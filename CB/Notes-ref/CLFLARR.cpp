//problem: https://www.spoj.com/problems/CLFLARR/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class DSU {
public:
    vector<int>parent;
    //constructor
    DSU(int n = 100) {
        parent.resize(n);
        //initially every node/element is the parent of itself
        iota(parent.begin(), parent.end(), 0);
    }



    //this fucntion will return the parent or the super parent of x
    int find(int x) {
        return (parent[x] == x ? x : (parent[x] = find(parent[x])));
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {

            parent[x] = max(parent[x], parent[y]);
            parent[y] = parent[x];
        }
    }


};
int main() {

    int n, q;
    cin >> n >> q;
    int l[200000], r[200000], c[200000];
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
    }
    DSU d(n + 2);
    int res[n + 2] = {0};
    for (int i = q - 1; i >= 0; i--) {
        int index = d.find(l[i]);
        while (index <= r[i]) {
            res[index] = c[i];
            d.unite(index, index + 1);
            index = d.find(index);
        }

    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
}
