//problem: https://www.spoj.com/problems/EXPEDI/


#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t; cin>>t;
    int n, d, f, fuel, l;
    while(t--){
        cin>>n;
        //will store the distance from the town and the fuel capcity at the stops 
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        //fuel: initial fuel with the vehicle
        //l: length from start to the town
        cin>>l>>fuel;
        //input distance is from the town, we want it to be from the start
        for(int i=0; i<n; i++){
            v[i].first= l- v[i].first;
        }
        sort(v.begin(), v.end());
        

        //priority queue to store the visited fuel pumps/stops
        priority_queue<int>visited;
        int x=0;
        bool flag=0;
        //remember that the truck consumes 1 unit of fuel to cover 1 unit of distance
        int prev=0;
        int answer=0;
        while(x<n){
            //v[i] is the destination

            if(fuel >= v[x].first - prev){
                fuel -= (v[x].first-prev);
                visited.push(v[x].second);
                prev=v[x].first;
            }

            else{
                //if the priority queue is empty, it means either we have either refuled at all the stations that we visited.
                //or we still haven't visited any gas/petrol/fuel station
                if(visited.empty()){
                    flag=1;
                    break;
                }

                fuel+= visited.top();
                visited.pop();
                answer++;
                //suppose we refueled but that is still not enough to reach the next stopage, so we can't increase the value of 'x'.
                //so, 'continue' won't increase x and loop will run again with the same value of 'x' thereby again checking the if(), else() condition.
                //and refueling again if required and if possible(empty na ho priority queue);
                continue;
            }
            x++;
        }
        //now we have exited the while loop, means we are at the last stop but yet to cover a distance to reach the town.
        if(flag==1){
            cout<<-1<<endl;
            continue;
        }
        if(fuel >= l-v[n-1].first){
            cout<<answer<<endl;
            continue;
        }
        
        while(fuel< l- v[n-1].first){
            if(visited.empty()){
                flag=1;
                break;                
            }
            fuel+= visited.top();
            visited.pop();
            answer++;
        }
            
        
        if(flag ==1){
            cout<<-1<<endl;
        }
        else{
            cout<<answer<<endl;
        }
    }
}

