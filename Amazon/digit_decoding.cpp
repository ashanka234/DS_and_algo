#include<iostream>
using namespace std;

int get_ways(char *str, int n)
{
    int dp[n+1];
    // for(int i=0; i<n+1; i++)
    //     dp[i] = 0;

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++)     //i is the length of current string
    {
        dp[i] = 0;
        
        //for 1-9
        if(str[i-1] > '0')
        {
            dp[i] = dp[i-1];        //recur for remaining string
        }

        //for 11-19 and 20-26
        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<='6') )
        {
            dp[i] += dp[i-2];       
        }
        // cout << dp[i] << " ";
    }

    return dp[n];
}

int main()
{
    char str[] = "1234";
    int n = strlen(str);
    //cout << n << endl;

    cout << get_ways(str, n) << endl;

    return (0);
}