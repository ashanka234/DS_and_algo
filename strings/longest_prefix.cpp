#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int get_min_length(string *arr, int n)
{
    int min_len = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i].length() < min_len)
            min_len = arr[i].length();
    }

    return min_len;
}

string longest_common_prefix(string *arr, int n)
{
    int min_len = get_min_length(arr, n);
    string ans;

    for(int i=0; i<min_len; i++)
    {
        int current_char = arr[0][i];

        for(int j=1; j<n; j++)
        {
            if(arr[j][i] != current_char)
            {
                if(ans.length()==0)
                    return "-1";
                else
                {
                    return ans;
                }
                
            }
        }
        ans.push_back(current_char);
    }

    return ans;
}

int main()
{
    int t, n;
    string *arr;

    cin >> t;

    while(t--)
    {
        cin >> n;
        arr = new string[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];

        cout << longest_common_prefix(arr, n) << endl;
    }

    return (0);
}