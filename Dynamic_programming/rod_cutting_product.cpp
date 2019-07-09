#include<iostream>
#include<algorithm>
using namespace std;

#define MODULO (10^9 + 7)

int max_product(int n)
{
    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        dp[i] = 0;
        for(int j=1; j<=i/2; j++)
        {
            dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
        }
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
        cout << max_product(n) % MODULO << endl;
   }

    return (0);
}

