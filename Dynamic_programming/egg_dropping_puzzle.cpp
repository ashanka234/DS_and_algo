#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int egg_dropping(int n, int k)
{
    int dp[n+1][k+1];

    //0 trials for 0 floors
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    //1 trials for 1 floor, however many eggs 
    for(int i=0; i<=n; i++)
    {
        dp[i][1] = 1;
    }

    //j trials for 1 egg, for jth floor
    for(int j=0; j<=k; j++)
    {
        dp[1][j] = j;
    }

    //calculated for 1 floors, 0 floors, 1 egg
    //now dp for rest from 2 floors and up, and 2 eggs and up

    for(int i=2; i<=n; i++)     //i is floor
    {
        for(int j=2; j<=k; j++)     //j is egg
        {
            dp[i][j] = INT_MAX;
            for(int x=1; x<=j; x++)     //try dropping from each floor up to jth floor
            {
                //iss floor ka trial is 1 count
                //agar iss floor pe toot gya - one egg less, and isse neeche waale floors mei dekhna hai 
                //agar ispe nhi toota - same no of eggs, and agle floor se end tak saare floors pe dekhna hai till j
                //take max because worst case mei pucha hai
                int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                //now take min of all the ans 
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }

    return dp[n][k];        //Time - O(n*k^2)
}

int main()
{
    int t,n,k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        cout << egg_dropping(n,k) << endl;
    }

    return (0);
}