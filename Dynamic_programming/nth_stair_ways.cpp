#include<iostream>
using namespace std;

#define MODULO 1000000007

int count_ways(int n)
{
    long dp[n+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = (dp[i-1]%MODULO + dp[i-2]%MODULO)%MODULO;
        //cout << dp[i] << " ";
    }
    //cout << endl;
    return dp[n];
}

int main()
{
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << count_ways(n) << endl;
    }
    return (0);
}