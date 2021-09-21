//cycle detection in an undirected graph using DSU

#include<iostream>
#include<list>
#include<deque>
#include<climits>
using namespace std;
#define ll long long

#define CINT ios_base::sync_with_stdio(false); cin.tie(NULL);

class Graph {
public:
	int V;
	list<pair<int, int>> l;  // list of edges

	//constructor
	Graph(int V = 10) {
		this->V = V;
	}

	void AddEdge(int u, int v) {
		l.push_back(make_pair(u, v));
	}

	//find function
	int FindSet(int i, int parent[]) {
		if (parent[i] == -1) {
			return i;
		}
		return FindSet(parent[i], parent);
	}

	//union function

	void Union_Set(int x, int y, int parent[]) {
		int s1 = FindSet(x, parent);
		int s2 = FindSet(y, parent);
		if (s1 != s2) {
			parent[s1] = s2;
		}
	}

	bool contains_cycle() {
		//DSU logic to see if the graph has any cycle or not
		//assuming that each node represents a set in itself
		int* parent  = new int[V];
		//initially every set is he parent of itself
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
		}

		// now we will iterate over the edge list and merge them
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = FindSet(i, parent);
			int s2 = FindSet(j, parent);
			if (s1 != s2) {
				Union_Set(s1, s2, parent);
			}
			else {
				return true;
			}
		}
		delete []parent;
		//cycle not found
		return false;

	}
};





int main() {

	CINT

	Graph G(4);
	G.AddEdge(0, 1);
	G.AddEdge(1, 2);
	G.AddEdge(2, 3);
	G.AddEdge(3, 0);
	if (G.contains_cycle()) {
		cout << "Cycle is Present\n";
	}
	else {
		cout << "Cycle is not Present\n";
	}
}


/*

0 ------- 1
|         |
|         |
|         |
3 ------- 4

*/
