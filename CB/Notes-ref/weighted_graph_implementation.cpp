#include <iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;
class Graph{
    private:
    unordered_map<string, list<pair<string, int>>> l;

    public:
    void addEdge(string x, string y, bool bidir, int weight){
        l[x].push_back(make_pair(y,weight));

        // if bi-directional
        if(bidir){
            l[y].push_back(make_pair(x, weight));
        }
    }
    void printAdjacencyList(){
        //we will extract every key-value pair one by one
        // it will be a pair, pair<string, list<pair<string, int>>>
        for(auto p:l){
            string city= p.first;
            list<pair<string, int>>neighbours=p.second;
            cout<<"city "<<city<<"--> ";
            //printing the list associated with this city
            for(pair<string, int>x: neighbours){
                string d= x.first;
                int dist= x.second;
                cout<<"("<<d<<","<<dist<<")  ";
            }
            cout<<endl;
        }
    }
};
int main() {
    Graph g;
    g.addEdge("A", "B", true, 20);  //true: bi-directional edge
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    //city(key here) will get printed in any order, since we are using an unordered map
    g.printAdjacencyList();
}

