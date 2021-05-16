#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<char>q;
    int freq[27] = {0};
    //Question says, input a stream of characters till you get a '.'

    char ch;
    cin >> ch;
    while (ch != '.') {
        q.push(ch);
        freq[ch - 'a']++;

        //query
        while (!q.empty()) {
            int index = q.front() - 'a';
            if (freq[index] > 1) {
                q.pop();
            }
            else {
                cout << q.front() << " ";
                break;
            }
        }

        // if the queue is empty
        if (q.empty()) {
            cout << "-1" << " ";
        }

        cin >> ch;
    }
}
