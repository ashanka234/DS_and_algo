#include<iostream>
#include<climits>
using namespace std;

int knapsack(int *val, int *weights, int n, int W)
{
    int dp[W+1];
    for(int i=0; i<W+1; i++)
        dp[i] = 0;

    for(int i=0; i<=W; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(weights[j] <= i)
            {
                dp[i] = max(dp[i], dp[i-weights[j]] + val[j]);
            }
        }
    }
    return dp[W];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,W;
        cin >> n >> W;
        int *val = new int[n];
        int *weight = new int[n];
        for(int i=0; i<n; i++)
            cin >> val[i];
        for(int i=0; i<n; i++)
            cin >> weight[i];

        cout << knapsack(val,weight,n,W) << endl;
    }

    return (0);
}