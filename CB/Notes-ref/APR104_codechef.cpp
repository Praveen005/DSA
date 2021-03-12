#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool con(char c) {
    if (c != 97 && c != 101 && c != 117 && c != 111 && c != 105) {
        return true;
    }
    return false;
}

void func(char* ch, int n) {
    if (!con(ch[0])) {
        cout << "False";
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (con(ch[i]) && con(ch[i + 1])) {
            cout << "False";
            return;
        }
    }
    cout << "True";
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    char ch[1008];
    cin >> ch;

    int n = strlen(ch);
    func(ch, n);

}
