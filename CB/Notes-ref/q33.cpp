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

            //ex : 4991  if suppose 4 is CB number then any substring formed using 4 won't be CB number
            //but substring formed by using 9 can be CB number
            //again if 49 if a CB number then any substring starting with zero or this particular 9 is will not be a CB number
            //this is why we write substrings in following order:
            /*
            4
            9
            9
            1
            49
            99
            91
            499
            991
            4991
            */

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