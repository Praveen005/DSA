// CB NUMBER

#include<iostream>

using namespace std;
#define ll long long

ll sToInt(string s1 ) {
    int ans = 0; int f = 1;
    for (int i = s1.length() - 1; i >= 0; i--) {
        ans += ((s1[i] - '0') * f);
        f *= 10;
    }
    return ans;
}
bool isCBnumber(string s) {
    ll number = sToInt(s);
    int b[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int i = 9;
    while (i >= 0) {
        if (number == b[i]) {
            return true;

        }
        i--;
    }
    if (number == 0 || number == 1) {
        return false;
    }
    i = 9;
    while (i >= 0) {
        if (number % b[i] == 0) {
            return false;

        }
        i--;
    }
    return true;

}
bool isValid(bool* visited , int start , int length) {
    for (int i = start; i < length; i++) {
        if (visited[i]) {
            return false;
        }

    }
    return true;

}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    bool visited[n] = {false};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int e = j + i;
            string sub = s.substr(j , e - j);
            if ( isCBnumber(sub) == true && isValid(visited , j, e) ) {
                count++;
                for (int k = j; k < e; k++) {
                    visited[k] = true;

                }
            }
        }
    }
    cout << count << endl;
}