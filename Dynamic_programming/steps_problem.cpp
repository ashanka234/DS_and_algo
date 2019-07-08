#include<iostream>
using namespace std;

int count_ways(int n)       //1,2 or 3 steps possible
{
    int dp[n+1];
    dp[0] = 1;      //1 way to climb 0 steps
    dp[1] = 1;      //1 way to climb 1 steps
    dp[2] = 2;      //2 ways - 1,1 or 2

    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main()
{
    int n, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << count_ways(n) << endl;
    }

    return (0);
}