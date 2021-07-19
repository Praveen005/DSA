#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
class person{
    public:
        string name;
        int age;

        //empty comparator likhna is a good practice if you're writting another
        // custom comparator below this.

        person(){

        }

        person(string n, int a){
            name=n;
            age=a;
        }
};

//comparator class
//STL requires comparator class and not comparator function
class personCompare{
    public:
    bool operator()(person A, person B){
        return A.age > B.age;
    }
};

int main() {
    priority_queue<person, vector<person>, personCompare>pq;

    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s;
        int a;
        cin>>s>>a;
        person p(s,a);
        pq.push(p);
    }
    //we just want to print who are the top three persons age wise
    int k; cin>>k;
    for(int i=0; i<k; i++){
        person q=pq.top();
        cout<<q.name<<" " <<q.age<<" "<<endl;
        pq.pop();
    }
}

