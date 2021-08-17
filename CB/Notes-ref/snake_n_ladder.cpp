
//Problem Image: https://bit.ly/2VR6isZ



#include <iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    private:
    map<T , list<T>>l;

    public:
 
    void addEdge(T x, T y){
        l[x].push_back(y);
    }
    //Distance traversed by BFS is shortest if the graph is un-weighted
    void bfs(T src, T dest){
        //following map will keep track of the distance of a node from the source node
        map<T, int>distance;
        map<T, T>parent;
        T node= src; //src: source node
        queue<T>q;
        q.push(src);
        //initially we will keep the distance of each node from source = infinite
        for(pair<T, list<T>> node:l){
            T x= node.first;
            distance[x]=INT_MAX;
        }
        //distance for source node will be zero.
        distance[src]= 0;
        parent[src]=src;
        while( !q.empty()){
            
            T temp= q.front();
            q.pop();
            
            //l[temp] will give all the neighbours 
            //we will push all its neighbours to the queue
            for(T nbr: l[temp]){
                if(distance[nbr]==INT_MAX){   //means still not visited
                    q.push(nbr);
                    //updating the distance of the visited node
                    distance[nbr]=distance[temp]+1;
                    parent[nbr]= temp;
                }
            }            
        }
        
    //print the distance of a node from the source.
                        //or//
    //you can say it will print the min number of throw required to reach the destination
    cout<<distance[dest]<<endl;


    //printing the path from source to destination
    cout<<"Path: ";
    T temp= dest;
    while(temp != src){
        cout<<temp<<" <-- ";
        temp=parent[temp];
    }
    cout<<src;
    cout<<endl;
    
    }

};
int main() {
    Graph<int>g;
    //input board
    int board[50]={0};
    board[2]= 13;  //ladder at 2 which will take you to 2+13 = 15;
    board[5]= 2;
    board[9]= 18;
    board[18]= 11;
    board[17]= -13;  // there is a snake at 17 that will bring you down to 17-13= 4;
    board[20]= -14;
    board[24]= -8;
    board[25]= 10;
    board[32]= -2;
    board[34]= -22;


    for(int i=1; i<=36; i++){
        for(int dice=1; dice<=6; dice++){
            int j= i+dice;
            j= j+board[j];
            g.addEdge(i,j);
        }
    }
    cout<<"Min. number of throw required to reach destination is: ";
    g.bfs(1,36);
}

// it will give you shotest path only. To print the path, we will keep another map, which
//will store the parent of each node


