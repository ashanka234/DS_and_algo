#include <iostream>
#include <climits>
using namespace std;

void print_coins(int *R, int n, int *coins)
{
    if(R[n-1] == -1)
    {
        return;     //no solution
    }

    int start = n-1;
    while(start != 0)
    {
        int j = R[start];
        cout << coins[j] << " ";
        start -= coins[j];
    }
    cout << endl;
}

int min_coins(int sum, int *coins, int n)
{
    int dp[sum+1];
    int R[sum+1];

    for(int i=0; i<sum+1; i++)
        R[i] = -1;
    for(int i=0; i<sum+1; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for(int j=0; j<n; j++)  //j is the coin      
    {
        for(int i=1; i<=sum; i++)   //i is the current amount
        {
            if(i - coins[j] >= 0)
            {
                if(dp[i-coins[j]] + 1 < dp[i])
                {
                    dp[i] = 1 + dp[i-coins[j]];
                    R[i] = j;
                }       //else dp[i] = INT_MAX
            }
        }
    }

   print_coins(R, sum+1, coins);
   return dp[sum];
}

int main()
{
    int t;
    cin >> t;
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);

    while(t--)
    {
        int sum;
        cin >> sum ;
        cout << min_coins(sum, coins, n) << endl;
        //min_coins(n, coins, len_coins);
       
    }

    return (0);
}