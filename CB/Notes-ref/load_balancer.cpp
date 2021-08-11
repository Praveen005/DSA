
//https://www.spoj.com/problems/BALIFE/


#include <iostream>
#include<cstdlib>
using namespace std;
int main() {
    int n;
    int loads[9001];
    while(1){
        cin>>n;
        if(n == -1){
            break;
        }
        int req_load=0;
        for(int i=0; i<n; i++){
            cin>>loads[i];
            req_load+=loads[i];
        }

        //load to distributed(equally) to every processor
        if(req_load % n != 0){
            cout<<-1<<endl;
            continue;
        }
        req_load /= n;
        int diff=0;
        int max_load=-1;
        for(int i=0; i<n; i++){
            //running difference
            diff+= (loads[i]- req_load);
            //-ve diff : load required on left partition
            //+ve diff : load to be transfered to the right partition
            int val= max(diff, -diff);     // I have to take absolute value of the diff.
            max_load= max(max_load, val);  // you could've done abs(diff)  :)
        }
        cout<<max_load<<'\n';
        
    }
}



