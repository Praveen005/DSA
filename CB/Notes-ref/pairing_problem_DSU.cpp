//Problem: https://hack.codingblocks.com/app/practice/1/627/problem

#include<iostream>
#include<list>
using namespace std;
#define ll long long
class Graph{
	public:
	int V;
	list<pair<int, int>>l;
	//constructor
	Graph(int V= 6){
		this->V= V;		
	}

	void addEdge(int x, int y){
		l.push_back(make_pair(x, y));
	}

	//we will write the find and the union function with path compression
	//and the union by rank optimisations

	int find_set(int i, int parent[]){
		if(parent[i]== -1){
			return i;
		}

		return parent[i]= find_set(parent[i], parent); //path compression
	}

	void Union_set(int i, int j, int parent[], int rank[]){
		//find the set which conatins the element i & j
		int s1= find_set(i, parent);
		int s2= find_set(j, parent);

		//union by rank/size optimisation
		if(s1 != s2){
            if(rank[s1]<rank[s2]){
			parent[s1]=s2;
			rank[s2]+= rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1] += rank[s2];
            }
        }
	}

	void Pairing(int n, int m){
		int* parent= new int[n];
		int* rank= new int[n];

		//initially every node is the parent of itself
		for(int i=0; i<n; i++){
			parent[i]= -1;
		}
		//initially the size of each node would be 1
		for(int i=0; i<n; i++){
			rank[i]=1;
		}
		for(auto p: l){
			Union_set(p.first, p.second, parent, rank);
		}
        
        int sum=0;
		for(int i=0; i<V; i++){
            //agar saare elements pe find_set function call hua hoga tab hi sab ka path compress hoga
            sum+= (n- rank[find_set(i, parent)]);
		}
		cout<<sum/2<<endl;
	}
};

int main() {
	int n, m; 
	cin>>n>>m;
	Graph g(n);
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		g.addEdge(a,b);
	}
	g.Pairing(n, m);
	return 0;
}
