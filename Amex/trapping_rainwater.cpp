#include<iostream>
#include<algorithm>
using namespace std;

int max_water_trapped(int *arr, int n)
{
    int *left = new int[n];
    int *right = new int[n];

    left[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        left[i] = max(left[i-1], arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        right[i] = max(right[i+1], arr[i]);
    }

    int waterFilled = 0;

    for(int i=0; i<n; i++)
    {
        waterFilled += (min(left[i], right[i]) - arr[i]);
    }

    return waterFilled;
}

int main()
{
    int t, n;
    int *arr;

    cin >> t;

    while(t--)
    {
        cin >> n;
        arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        cout << max_water_trapped(arr, n) << endl;
    }

    return (0);
}