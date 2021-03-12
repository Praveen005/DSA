
#include<stdio.h>

void sort(int a[] , int n) {
    int iteration, j;
    for ( iteration = 1; iteration < n - 1; iteration++) {
        int k; int var;
        for (j = 0; j <= n - 1 - iteration; j++) {
            k = j + 1;
            if (a[j] > a[k]) {
                var = a[k];
                a[k] = a[j];
                a[j] = var;
            }
        }
    }

}

int main() {
    // n and m are  no of elements in two arrays
    int n , m;
    scanf("%d %d ", &n , &m);
    int a[10000];
    int b[10000];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    for (i = 0; i < m; i++) {

        scanf("%d", &b[i]);
    }



    int com[20005] ;
    for (i = 0; i < n; i++) {
        if (i < n) {
            com[i] = a[i];
        }

    }
    for (i = n; i < n + m; i++) {

        com[i] = b[i - n];


    }

    sort(com, n + m);
    for (i = 0; i < (n + m); i++) {
        printf("%d ", com[i]);
    }
}