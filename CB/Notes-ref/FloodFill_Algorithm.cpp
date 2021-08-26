#include <iostream>
#include<list>
using namespace std;

const int R = 15, C = 30;

// west, north, east south
int dx[] = { -1, 0, 1, 0}; //means agar west jana hai to x= x +(-1) hoga and so on
int dy[] = {0, 1, 0, -1};

//ch- character to be replaced.
//color: the charcter which will replace 'ch';
//i, j - gives the position of the starting pixel/position
void FloodFill(char mat[][50], int i, int j, char ch, char color) {
    //base case: matrix bounds
    if (i < 0 || j < 0 || i >= R || j >= C) {
        return;
    }

    //figure(apple here) boundary condition
    if (mat[i][j] != ch) {
        return;
    }

    //recursive call
    //replacing the character
    mat[i][j] = color;
    //can move in all four direction from this point
    for (int k = 0; k < 4; k++) {
        FloodFill(mat, i + dx[k], j + dy[k], ch, color);
    }

}

void printMatrix(char mat[][50]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // cin>>r>>c;

    char input[30][50];

    //we will replace all the dots inside the boundary region with some other character.
    //inner dots: one connected component
    //green dandi: another connected comp.
    //outer region is another connected component.
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input[i][j];
        }
    }

    // printMatrix(mat, r, c);

    FloodFill(input, 8 , 13, '.', 'r');
    // FloodFill(input, 0 , 0, '.', '+');
    // FloodFill(input, 2 , 14, '.', 'g');
    printMatrix(input);



}

/*

Input:


..............................
.............#####............
.............#...#............
.....#########...#######......
....###.....######.....###....
...##....................##...
..##......................#...
..##.....................##...
..###...................##....
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........




output:


..............................
.............#####............
.............#...#............
.....#########...#######......
....###rrrrr######rrrrr###....
...##rrrrrrrrrrrrrrrrrrrr##...
..##rrrrrrrrrrrrrrrrrrrrrr#...
..##rrrrrrrrrrrrrrrrrrrrr##...
..###rrrrrrrrrrrrrrrrrrr##....
....###rrrrrrrrrrrrrrrr###....
......###rrrrrrrrrrrr###......
........###rrrrrrrr###........
..........##########..........
..............................
...........A.P.P.L.E..........


*/

