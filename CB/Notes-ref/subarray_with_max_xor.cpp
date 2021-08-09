/*
	calculate max xor value for any subarray of the given input array.
	
	1. make cumulative xor array
	2. aplly the method of max xor pair

*/

#include <iostream>
using namespace std;
class Node{
    public:
    //bits can either be 0 or 1
    //If the current bit is 0 then we will create a child node to the left else to the right.
    Node* left;    // left node means 0
    Node* right;    // right node means 1

    //constructor
    Node(){
        left=NULL;
        right=NULL;
    }
};

class Trie{
    public:
    Node* root;

    //constructor
    Trie(){
        root= new Node();   //root node of the tree
    }

    void insert(int value){
        Node* temp=root;
        for(int j=31; j>=0; j--){
            int bit=(value>>j)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left=new Node();
                }
                temp=temp->left;                
            }
            else{
                if(temp->right==NULL){
                    temp->right=new Node();
                }
                temp=temp->right;
            }
        }
    }

    //Helper function
    //this function will extract all the bits from the given number and will calculate the 
    // max xor it can make with an other number already inserted in the Trie.
    int get_xor(int value){
        int xor_value=0;
        Node* temp=root;
        for(int j=31; j>=0; j--){
            int bit = (value>>j)&1;
            if(bit){
                if(temp->left){
                    xor_value+= (1<<j);
                    temp= temp->left;
                }
                else{
                    temp= temp->right;
                }
            }
            else{
                if(temp->right){
                    xor_value+= (1<<j);
                    temp= temp->right;
                }
                else{
                    temp= temp->left;
                }
            }
        }
        return xor_value;
    }
    
    int max_xor(int* input, int n){
        int max_xor_until_now=0;
        for(int i=0; i<n; i++){
            int value= input[i];
            insert(value);
            int current_xor= get_xor(value);
            max_xor_until_now= max( max_xor_until_now, current_xor);
        }
        return max_xor_until_now;
    }
};


int main() {
    int n; cin>>n;
    int input[100];
    //make an array of size 1 greater than the input, to store cumulative xor
    int cum_xor[101];
    cum_xor[0]=0;
    for(int i=0; i<n; i++){
        cin>>input[i];
        cum_xor[i+1]= (cum_xor[i]^input[i]);
    }
    Trie t;
    //cumulative xor array has now n+1 elements
    cout<<t.max_xor(cum_xor, n+1)<<endl;
}

/*
sample input:
6
8 1 2 12 7 6

sample output:
15

*/

