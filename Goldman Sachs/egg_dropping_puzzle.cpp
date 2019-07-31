#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int egg_drop(int n, int k)
{
    int dp[n+1][k+1];

    //i is the no of eggs
    //j is the no of floors

    for(int i=0; i<=n; i++)
    {
        dp[i][1] = 1;       //kitne bhi eggs ho, but 1 floor
        dp[i][0] = 0;       //kitne bhi eggs, but 0 floors
    }

    //kitne bhi floors, but 1 egg only
    for(int j=0; j<=k; j++)
    {
        dp[1][j] = j;       //jitne floor hai, utne attemp chahiye
    }

    //2 eggs se check krna start kro
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=k; j++)     //2nd floor se check krna start
        {
            dp[i][j] = INT_MAX;

            //now start dropping i no of eggs from each floor till j 
            for(int x=1; x<=j; x++)
            {
                int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if(res < dp[i][j])
                    dp[i][j] = res;
            }
        }

    }
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << egg_drop(n, k) << endl;

    return (0);
}