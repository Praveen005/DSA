//problem: https://codeforces.com/contest/1172/problem/A

#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int check(int*b, int n, int index) {
    for (int i = 1; i < index; i++) {
        if (b[i] != 0 and i > (b[i] - b[n] - 1)) {
            return INT_MAX;
        }
    }

    int steps = 0;
    for (int i = 1; i < index; i++) {
        int val = b[i];
        if (i >= b[i] and val != 0) {
            steps = max(steps, (i - val + 1));
        }
    }
    return steps + (n - (n + 1 - index));

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int a[300005] = {0};
    int b[300005] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int steps = 0;
    for (int i = 1; i <= n; i++) {
        int val = b[i];
        if (i >= b[i] and val != 0) {
            steps = max(steps, (i - val + 1));
        }
    }
    steps += n;

    int index = -1;
    for (int i = 0; i <= n; i++) {
        if (b[i] == 1) {
            index = i;
            break;
        }
    }
    int result;
    if (index != -1) {
        bool flag = 0;
        int j = index + 1;
        for (; j <= n; j++) {
            if (b[j] != (b[j - 1] + 1)) {
                flag = 1;
            }
        }
        if (index == n || flag == 0) {
            result = check(b, n, index);
            steps = min(result, steps);
        }
    }

    cout << steps;
}



/*
refer: https://codeforces.com/blog/entry/67511   :read comment by shpvb

The approach is that you have to play some blank cards in the beginning and then play the cards 1 to n in a row. 
if you see by taking examples. Now suppose you are starting your moves for playing cards 1 to n. 
So what are the requirement: Card 1 present in hand. 
Card 2 present in hand or at the top of the pile. Card 3 present in the hand or at the top or the second from 
top in the pile ... and so on. 
Suppose some condition is violated, then we have to play blank cards to get the card i before its turn to play 
omes. That comes out to be pi — i + 1. 
If we play these many blank cards so the top of pile above this position are already in our hand. 
So the ans is max(pi — i + 1) + n. 
We add n for playing the cards 1 to n.

for corner case see the notebook.
*/


