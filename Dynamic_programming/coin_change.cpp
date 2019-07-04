#include <iostream>
#include <climits>
using namespace std;

int *min_coins(int sum, int *coins, int n)
{
    int dp[sum+1];
    int coins_count[n];

    for(int i=0; i<n; i++)
        coins_count[i] = 0;
    for(int i=0; i<sum+1; i++)
        dp[i] = 0;

    dp[0] = 0;

    for(int i=1; i<=sum; i++)       //i is the current amount
    {
        dp[i] = INT_MAX;
        for(int k=0; k<n; k++)
        {
            if(i - coins[k] >= 0)
            {
                if(dp[i-coins[k]] < dp[i])
                    coins_count[k]++;
                dp[i] = min(dp[i], dp[i-coins[k]]+1);
            }
        }
    }
    //return dp[sum];
    return coins_count;
}

int main()
{
    int t;
    cin >> t;
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int len_coins = sizeof(coins)/sizeof(int);

    while(t--)
    {
        int n;
        cin >> n ;
        //cout << min_coins(n, coins, len_coins) << endl;
        int *ans = min_coins(n, coins, len_coins);
        for(int i=0; i<len_coins; i++)
        {
            // for(int j=1; j<=ans[i]; j++)
            //     cout << coins[i] << " ";
            //cout << endl;
            cout << ans[i] << " ";
        }
cout << endl;
    }
    return (0);
}