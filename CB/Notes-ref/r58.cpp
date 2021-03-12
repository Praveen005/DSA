/*
    problem says there is a wall of size 4xN . we have tiles of size (1,4) & (4,1).
    we have to find the total number of ways to arrange the tiles on the wall/table/whatever :)

    note: '4' here is width of the wall       <--------N--------->

                                         1    --------------------
                                         2    -                  -
                                         3    -                  -
                                         4    --------------------

*/
#include<iostream>
#include<cstring>
using namespace std;
int PlaceTheTiles(int N) {
    if (N <= 3) {
        return 1;
    }
    int i = PlaceTheTiles(N - 1);
    int j = PlaceTheTiles(N - 4);
    return i + j;

}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Tilling problem using recursion

    int N; cin >> N;
    cout << PlaceTheTiles(N) << endl;
}
