#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int max_stolen(int n, int *money)
{
    int dp[n+1];
    dp[0] = 0;
    dp[1] = money[0];

    for(int i=2; i<=n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + money[i-1]);
    }

    return dp[n];
}

int main()
{
    int t, n;
    int *money;

    cin >> t;
    while(t--)
    {
        cin >> n;
        money = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> money[i];
        }

        cout << max_stolen(n, money) << endl;
    }

    return (0);
}