#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int lps(char *str, int i, int j)
{
    //only 1 char
    if(i==j)
    {
        return 1;
    }

    //2 chars 
    if(i==j-1)
    {
        if(str[i] == str[j])        //both are same
        {
            return 2;
        }
        else        //no palindromic subseq
        {
            return 0;
        }
    }

    if(str[i] == str[j])
    {
        return 2 + lps(str, i+1, j-1);
    }

    return max( lps(str, i, j-1), lps(str, i+1, j) );
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
        cout << lps(str, 0, n-1) << endl;
    }

    return (0);
}