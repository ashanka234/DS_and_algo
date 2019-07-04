#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, w;
        cin >> n >> w;
        int *val = new int[n];
        int *weights = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> val[i];
        }

        for(int i=0; i<n; i++)
        {
            cin >> weights[i];
        }

        int dp[1001][1001] = {0};
        dp[0][0] = 0;

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=w; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                
                else if(weights[i-1] <= j)
                    dp[i][j] = max (val[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
                
            }
        }

        cout << dp[n][w] << endl;
    }

    return (0);
}