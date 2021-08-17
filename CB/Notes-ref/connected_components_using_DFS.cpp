#include <iostream>
#include<map>
#include<list>
using namespace std;

//we don't know the data type of the nodes
template<typename T>
class Graph{
    private:
    map<T, list<T>>l;

    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    //In every dfs_helper() call, it will return back after printing that component
    //of the graph which contains the given(argument wala) non-visited node.
    void dfs_helper(T src, map<T, bool>& visited){
        cout<<src<<" ";
        visited[src]= true;

        //ab mai src ke neighbouring nodes ko khojunga. Jo ki mujhe l[src] se milega
        for(auto nbr: l[src]){
            T node= nbr;
            if(visited[node]== false){
                dfs_helper(node, visited);
            }
        }


    }

    void dfs(void){
        //keep a map to store the status of visit 
        map<T, bool> visited;
        //initially all the nodes are non-visited
        for(pair<T, list<T>> p: l){
            T node= p.first;
            visited[node]= false;
        }

        //Jitne components hain utni baar dfs_helper() call hoga.
        
        int count=0;
        for(pair<T, list<T>> p: l){
            T node= p.first;
            if(!visited[node]){
                count++;
                cout<<"component "<<count<<"--> ";
                dfs_helper(node, visited);
                cout<<endl;
            }
        }
        cout<<"\nNumber of connected components in the graph: "<<count<<endl;

    }
};
int main() {
    Graph<int> G;
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(0,4);

    G.addEdge(5,6);
    G.addEdge(6,7);

    G.addEdge(8,8);
    G.dfs();
}


/*

(2)---------(1)
|            |
|            |
|            |
(3)---------(0)
|
|
|
(4)--------(5)

*/
