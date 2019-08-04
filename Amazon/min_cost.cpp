#include<iostream>
#include<climits>
using namespace std;

int get_min_cost(int arr[][10], int m, int n)
{
    if(m<0 || n<0)
        return INT_MAX;

    if(m==0 && n==0)
        return arr[m][n];

    return arr[m][n] + min(get_min_cost(arr, m-1, n),
                            min(get_min_cost(arr, m, n-1),
                            get_min_cost(arr, m-1, n-1)));
}

int get_min_cost_DP(int arr[][10], int m, int n)
{
    int dp[m+1][n+1];

    // for(int i=0; i<m+1; i++)
    //     for(int j=0; j<n+1; j++)
    //         dp[i][j] = 0;

    dp[0][0] = arr[0][0];

    for(int i=1; i<=m; i++)      //set firts col
        dp[i][0] = dp[i-1][0] + arr[i][0];

    for(int j=1; j<=n; j++)          //set first row
        dp[0][j] = dp[0][j-1] + arr[0][j];

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = min(dp[i-1][j],
                            min(dp[i][j-1],
                                dp[i-1][j-1])) + arr[i][j];
        }
    }

    return dp[m][n];
}

int main()
{
    int cost_arr[10][10] = { {1, 2, 3}, 
                            {4, 8, 2}, 
                            {1, 5, 3} };
    int r = 3, c = 3;

    cout << "Recursion: " << get_min_cost(cost_arr, r-1, c-1) << endl;
    cout << "DP: " << get_min_cost(cost_arr, r-1, c-1) << endl;

    return (0);
}