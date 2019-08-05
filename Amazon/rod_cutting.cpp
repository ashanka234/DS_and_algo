#include<iostream>
#include<climits>
using namespace std;

int get_max_val(int *arr, int n)
{
    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++)     //current length of rod
    {
        int max_cost = INT_MIN;
        for(int j=0; j<i; j++)
        {
            max_cost = max(max_cost, arr[j] + dp[i-1-j]);
        }
        dp[i] = max_cost;
    }

    return dp[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    cout << get_max_val(arr, n) << endl;

    return (0);
}