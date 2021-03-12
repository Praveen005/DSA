// C code for  sin function
#include <stdio.h>
#include <math.h>



void calculate_sin(double n)
{
    double accuracy = 0.0001, denominator, sinx, sinValue;

    // Converting degrees to radian
    n = n * (3.14159265 / 180.0);

    double x1 = n;
    sinx = n;


    sinValue = sin(n);
    int i = 1;
    do
    {
        denominator = 2 * i * (2 * i + 1);
        x1 = -x1 * n * n / denominator;
        sinx = sinx + x1;
        i = i + 1;
    }
    while (accuracy <= fabs(sinValue - sinx));
    if (sinx > 0 && sinx < 1);
    printf("%0.8lf", sinx);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // angle in degree
    double n;
    scanf("%lf", &n);
    calculate_sin(n);
    return 0;
}