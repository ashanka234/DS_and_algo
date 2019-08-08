#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void get_leaders(int *arr, int n)
{
    vector<int> ans;
    int max=INT_MIN;

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }

    //print the vector in reverse
    for(int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";
}

int main()
{
    int n, t;
    int *arr;

    cin >> t;
    while(t--)
    {
        cin >> n;
        arr = new int[n];

        for(int i=0; i<n; i++)
            cin >> arr[i];

        get_leaders(arr, n);
        cout << endl;
    }

    return (0);
}