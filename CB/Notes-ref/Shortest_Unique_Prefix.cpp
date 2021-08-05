#include <iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    char data;
    unordered_map<char, Node*>children;
    bool terminal;
    int freq;

    Node(char ch){
        data=ch;
        terminal=false;
        freq=1;
    }
};

class Trie{
    private:
    Node* root;
    int count;
    public:
    Trie(){
        root= new Node('\0');
        count=0;
    }

    void insert(char* w){
        Node* temp=root;
        for(int i=0; w[i] != '\0'; i++){
            char ch=w[i];
            if(temp->children.count(ch)){
                // temp->freq++;
                temp=temp->children[ch];
                temp->freq++;
            }
            else{
                Node* n= new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }


    bool search(char* w){
        Node* temp=root;
        for(int i=0;  w[i] != '\0'; i++){
            char ch=w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp=temp->children[ch];
            }
        }
        return temp->terminal;
    }

    string func(char* w){
        Node* temp=root;
        string result="";
        for(int i=0; w[i] != '\0'; i++){
            char ch=w[i];
            temp=temp->children[ch];
            result+=ch;

            if(temp->freq ==1){
                return result;
            }
        }
        result="-1";
        return result;
    }
};
int main() {
    char words[][20]={"cobra", "dog", "dove", "duck", "zebra","no", "not"};
    int n= sizeof(words)/sizeof(words[0]);
    Trie t;
    for(int i=0; i<n; i++){
        t.insert(words[i]);
    }
    
    
    for(int i=0; i<n; i++){
        string ch=t.func(words[i]);
        cout<<ch<<" ";
    }
}

/*
output:
c dog dov du z -1 not

*/
