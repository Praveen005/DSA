#include<iostream>
//#include<algorithm>
using namespace std;
int main() {


    int a[] = {1, 1, 1, 1, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);

    // sort(a, a + n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++ ) {
            if (a[j] == a[i]) {
                a[j] = a[i] + 1;
            }
        }

    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}