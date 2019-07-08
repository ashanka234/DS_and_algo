#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int max_subseq_sum(int *arr, int n)
{
    int i, j, max=arr[0];
    int dp[n];

    for(i=0; i<n; i++)
    {
        dp[i] = arr[i];
    }

    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(arr[i] > arr[j] && dp[j]+arr[i] > dp[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    return max;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        cout << max_subseq_sum(arr, n) << endl;
    }

    return (0);
}