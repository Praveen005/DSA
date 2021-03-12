#include<iostream>//kadane’s algorithm(maximum sub array sum O(n) complexity
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    for (int p = 1; p <= t; p++)
    {
        cin >> n;
        int *arr = new int[n];
        int currentsum = 0;
        int maxsum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            currentsum = currentsum + arr[i];
            if (currentsum < 0)
            {
                currentsum = 0;
            }
            maxsum = max(currentsum, maxsum);
        }
        cout << maxsum << endl;
        // return 0;
    }
}
