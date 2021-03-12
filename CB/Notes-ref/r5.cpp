// #include<iostream>
// using namespace std;
// int multiplyMatrix(int a[100][100], int b[100][100], int x , int y, int z) {
//     int i, j = 0;
//     int sum = 0;
//     for (i = 0; i < z; i++) {
//         sum += a[x][i] * b[i][y];
//     }
//     return sum;
// }
// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     // code for finding the product of two arrays

//     // 2 3  1 3
//     // 5 6  2 4

//     // here n1 and m1 represents the no of rows and columns in first matrix
//     /// here n2 and m2 represents the no of rows and columns in 2nd matrix
//     int n1, m1;
//     cin >> n1 >> m1;

//     // 1st matrix
//     int a[100][100];
//     int i, j;
//     for (i = 0; i < n1; i++) {
//         for (j = 0; j < m1; j++) {
//             cin >> a[i][j];
//         }
//     }

//     //2nd matrix
//     int n2, m2;
//     cin >> n2 >> m2;
//     int b[100][100];
//     for (i = 0; i < n2; i++) {
//         for (j = 0; j < m2; j++) {
//             cin >> b[i][j];
//         }
//     }
//     cout << endl << "1st matrix : " << endl;
//     for (i = 0; i < n1; i++) {
//         for (j = 0; j < m1; j++) {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl << "2nd matrix : " << endl;

//     for (i = 0; i < n2; i++) {
//         for (j = 0; j < m2; j++) {
//             cout << b[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;


//     if (m1 != n2) {
//         printf("Multiplication of matrix not feasible.\n");
//     }

//     else {
//         int prod[n1][m2];

//         for (i = 0; i < n1; i++) {
//             for (j = 0; j < m2; j++) {
//                 prod[i][j] = multiplyMatrix(a, b, i, j, n2);
//             }
//         }
//         cout << endl << "product of two matrices : " << endl;
//         for (i = 0; i < n1; i++) {
//             for (j = 0; j < m2; j++) {
//                 cout << prod[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// }



#include<stdio.h>

int multiplyMatrix(int a[100][100], int b[100][100], int x , int y, int z) {
    int i, j = 0;
    int sum = 0;
    for (i = 0; i < z; i++) {
        sum += a[x][i] * b[i][y];
    }
    return sum;
}
int main() {


    // here n1 and m1 represents the no of rows and columns in first matrix
    /// here n2 and m2 represents the no of rows and columns in 2nd matrix
    int n1, m1;
    scanf("%d %d", &n1, &m1);
    // cin >> n1 >> m1;

    // 1st matrix
    int a[100][100];
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m1; j++) {
            scanf("%d", &a[i][j]);
            // cin >> a[i][j];
        }
    }

    //2nd matrix
    int n2, m2;
    scanf("%d %d", &n2, &m2);
    // cin >> n2 >> m2;
    int b[100][100];
    for (i = 0; i < n2; i++) {
        for (j = 0; j < m2; j++) {
            scanf("%d", &b[i][j]);
            // cin >> b[i][j];
        }
    }
    printf("\n 1st matrix  \n");
    // cout << endl << "1st matrix : " << endl;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m1; j++) {
            printf("%d ", a[i][j]);
            // cout << a[i][j] << " ";
        }
        printf("\n");
        // cout << endl;
    }
    printf("\n 2nd matrix : \n");
    // cout << endl << "2nd matrix : " << endl;

    for (i = 0; i < n2; i++) {
        for (j = 0; j < m2; j++) {
            printf("%d ", b[i][j]);
            // cout << b[i][j] << " ";
        }
        printf("\n");
        // cout << endl;
    }
    printf("\n");
    // cout << endl;


    if (m1 != n2) {
        printf("Multiplication of matrix not feasible.\n");
    }

    else {
        int prod[n1][m2];

        for (i = 0; i < n1; i++) {
            for (j = 0; j < m2; j++) {
                prod[i][j] = multiplyMatrix(a, b, i, j, n2);
            }
        }
        printf("\n product of two matrices : \n");
        // cout << endl << "product of two matrices : " << endl;
        for (i = 0; i < n1; i++) {
            for (j = 0; j < m2; j++) {
                printf("%d ", prod[i][j]);
                // cout << prod[i][j] << " ";
            }
            printf("\n");
            // cout << endl;
        }
    }
}