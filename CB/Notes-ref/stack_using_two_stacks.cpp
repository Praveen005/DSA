//Implementing a Queue using two stacks
#include <iostream>
#include<stack>
using namespace std;
template<typename T>
class queue{
    private:
    stack<T>s1;
    stack<T>s2;

    public:

    // we need to implement Push, Pop, front, empty, size functions

    void push(T data){
        s1.push(data);
    }

    void pop(){
        if(s1.empty()){
            return;
        }

        while(s1.size()>1){
            T val=s1.top();
            s2.push(val);
            s1.pop();
        }

        s1.pop();
        
        //Transfer the element back to s1 from s2
        while(!s2.empty()){
            T val=s2.top();
            s1.push(val);
            s2.pop();
        }
    }


    T front(){
        while(s1.size()>1){
            T val=s1.top();
            s2.push(val);
            s1.pop();
        }
        T value=s1.top();
        s1.pop();
        s2.push(value);
        //Transfer the element back to s1 from s2
        while(!s2.empty()){
            T val=s2.top();
            s1.push(val);
            s2.pop();
        }
        return value;
    }

    int size(){
        return s1.size()+s2.size();
    }

    bool empty(){
        return size()==0;
    }

};
int main() {
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);


    while(! q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

