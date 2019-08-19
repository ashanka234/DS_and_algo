#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int getMinDiff(int *arr, int n, int m)
{
    sort(arr, arr+n);

    int min_diff = INT_MAX;
}

int main()
{
    int n, m, t;
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

        cin >> m;

        cout << getMinDiff(arr, n, m) << endl;
    }

    return (0);
}