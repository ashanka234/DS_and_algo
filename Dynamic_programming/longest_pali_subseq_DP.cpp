#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lps(char *str, int n)
{
    int dp[n][n];
    int i, j, curr_len;

    //strings of length 1 => palindrome
    for(i=0; i<n; i++)
    {
        
    }
}

int main()
{
    int t;
    char str[1000];
    
    cin >> t;
    while(t--)
    {
        cin >> str;
        int n = strlen(str);
        //cout << n ;
        cout << lps(str, n) << endl;
    }

    return (0);
}