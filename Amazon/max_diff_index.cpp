#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int get_max_diff(int *arr, int n)
{
    int ans;
    int i, j;

    int *Lmin = new int[n];
    int *Rmax = new int[n];

    Lmin[0] = arr[0];
    Rmax[n-1] = arr[n-1];

    for(int i=1; i<n; i++)
    {
        Lmin[i] = min(arr[i], Lmin[i-1]);
    }

    for(int j=n-2; j>=0; j--)
    {
        Rmax[j] = max(arr[j], Rmax[j+1]);
    }

    i=0; j=0; ans = INT_MIN;

    while(i<n && j<n)
    {
        if(Lmin[i] < Rmax[j])
        {
            ans = max(ans, j-i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}   

int main()
{
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};  
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << get_max_diff(arr, n) << endl;

    return (0);
}