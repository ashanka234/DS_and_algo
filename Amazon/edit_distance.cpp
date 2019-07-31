#include<iostream>
#include<cstring>
using namespace std;

//yeh s1 ko s2 banayega, not vice versa
int edit_dist(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)     //current length of first string
    {
        for(int j=0; j<=n; j++)     //current length of second string
        {
            //if first string is empty, we need to insert all j no. of chars of s2
            if(i==0)
            {
                dp[i][j] = j;
            }

            //if second str is empty, remove all i no. of chars of s1
            else if(j==0)
            {
                dp[i][j] = i;
            }

            //if last chars of both are same
            //curr length is i and j, so last chars will be at i-1 and j-1 indexes
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];        //then check previous state, means ek length kam for both
            }

            //last case is that end chars are different
            //so check all 3 possible operations and take min 
            else
            {
                dp[i][j] = 1 + min(dp[i][j-1],      //insert into s1
                                min(dp[i-1][j],     //remove from s1
                                dp[i-1][j-1]));  //replace last chars of both
            }
            
        }
    }

    return dp[m][n];
}

int main()
{
    string s1 = "sunday";
    string s2 = "saturday";

    int m = s1.length();
    int n = s2.length();

    cout << edit_dist(s1, s2, m, n) << endl;

    return (0);
}