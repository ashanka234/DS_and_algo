#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int rod_cutting(int n, int *prices)
{
    int dp[n+1];    //dp will store ans for i length
    dp[0] = 0;      //price for rod of 0 length is 0

    for(int i=1; i<=n; i++)
    {
        dp[i] = INT_MIN;
        for(int j=0; j<i; j++)      //j is the prices
        {
            dp[i] = std::max(dp[i], dp[i-1-j] + prices[j]);     //current price + price till length i-1
        }
    }

    return dp[n];
}

int main()
{
    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int *prices = new int[n];
        
        for(int i=0; i<n; i++)
        {
            cin >> prices[i];       //price[]i is for length i+1
        }

        cout << rod_cutting(n, prices) << endl;
    }

    return (0);
}