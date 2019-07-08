#include<iostream>
using namespace std;

int coin_change(int sum, int *coins, int n)
{
    int dp[sum+1];
    for(int i=0; i<sum+1; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i=0;i <n; i++)
    {
        for(int j=coins[i]; j<=sum; j++)
        {
            dp[j] += dp[j-coins[i]];
        }
    }

    return dp[sum];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, amt;
        cin >> n;       //no. of coins
        int *coins = new int[n];
        for(int i=0; i<n; i++)
        {
            cin >> coins[i];
        }
        cin >> amt;
        // for(int i=0; i<n; i++)
        //     cout << coins[i] << " ";
        cout << coin_change(amt, coins, n) << endl;
    }

    return (0);
}