#include<iostream>
using namespace std;

bool is_subset_sum_zero(int *arr, int n, int i, int curr_sum)
{
    //base case
    if(i==n)    //reached end of array
    {
        return false;
    }

    curr_sum += arr[i];
    cout << curr_sum << " ";
    if(curr_sum == 0)
    {
        return true;
    }
    return is_subset_sum_zero(arr, n, i+1, curr_sum);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        if(is_subset_sum_zero(arr, n, 0, 0)) 
        {
            cout << "Yes\n";
        }
        else
        {
            cout <<"No\n";
        }
        
    }

    return (0);
}