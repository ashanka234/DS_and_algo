#include<iostream>
using namespace std;

void print_fibo(int n)
{
    long long dp[n+2];
    dp[0] = 0;
    dp[1] = 1;  //first fibo is 1
    cout << dp[1] << " ";

    for(int i=2; i<=n; i++)
    {
        //cout << dp[i-1] << " ";
        dp[i] = dp[i-1] + dp[i-2];
        cout << dp[i] << " ";
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        print_fibo(n);
        cout << endl;
    }

    return (0);
}