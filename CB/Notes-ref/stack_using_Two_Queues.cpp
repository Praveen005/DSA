//Implementing a stack using two queues

#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class stack{
    private:
    queue<T>q1;
    queue<T>q2;

    public:

    void push(T data){
        q1.push(data);
    }
    int size(){
        return q1.size() + q2.size();
    }
    bool empty(){
        return size()==0;
    }
    void pop(){
        if(q1.empty()){
            return;
        }

        while(q1.size()>1){
            T val=q1.front();
            q2.push(val);
            q1.pop();
        }
        q1.pop();
        swap(q1,q2);
    }

    T top(){
            
            while(q1.size()>1){
                T val=q1.front();
                q1.pop();
                q2.push(val);
            }
            T value=q1.front();
            q2.push(value);
            q1.pop();
            swap(q1,q2);
            return value;

       
    }
};
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

