//Used sliding window concept.

#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char a[]="abcdefghc";
    int n= strlen(a);
    int current_length=1;
    int max_length=1;

    //form an array to store the last occurance of a character
    int visited[256];

    //-1 means the character hasn't occured yet.
    for(int i=0; i<256; i++){
        visited[i]=-1;
    }

    visited[a[0]]=0;  //Means 1st character(jo bhi hai) has 1st occurance at 0th index

    for(int i=1; i<n; i++){
        int last_occurance=visited[a[i]];
        //Expansion
        //i.e. either the character has yet not been encountered or not present in the window
        if(visited[a[i]]==-1  || i-last_occurance > current_length ){
            current_length++;
        }

        //Expansion + contarction
        else{
            current_length=i-last_occurance;
        }
        visited[a[i]]=i;
        max_length=max(max_length, current_length);
    }
    cout<<max_length<<endl;

}

