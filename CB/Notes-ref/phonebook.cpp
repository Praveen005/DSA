//one contact can have multiple phone numbers

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    //instead of a vector of string, you can use  long long int there
    unordered_map<string, vector<string>>phonebook;
    phonebook["Prateek"].push_back("9801");
    phonebook["Prateek"].push_back("9802");
    phonebook["Prateek"].push_back("9803");
    phonebook["Prateek"].push_back("9804");
    phonebook["Prateek"].push_back("9805");
    phonebook["Prateek"].push_back("9806");
    phonebook["Ganesh"].push_back("7801");
    phonebook["Ganesh"].push_back("7501");
    phonebook["Ganesh"].push_back("9871");
    phonebook["Ganesh"].push_back("9813");

    for(auto p: phonebook){
        cout<<"Name: "<<p.first<<" --> ";
        for(string s:p.second){
            cout<<s<<" ";
        }
        cout<<endl;
    }

    //making a search query
    string name;
    cin>>name;

    if(phonebook.count(name) !=0){
        for(string s: phonebook[name]){
            cout<<s<<" ";
        }
    }
    else{
        cout<<"Absent";
    }
}

/*
input:
Prateek

output:
Name: Ganesh --> 7801 7501 9871 9813 
Name: Prateek --> 9801 9802 9803 9804 9805 9806 
9801 9802 9803 9804 9805 9806 


*/

