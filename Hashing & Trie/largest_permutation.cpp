#include<iostream>
using namespace std;

void k_swap_permutation(int *arr, int n, int k)
{
    int *pos_map = new int[n+1];

    for(int i=0; i<n; i++)
    {
        pos_map[arr[i]] = i;
    }

    for(int i=0; i<n && k>0; i++)
    {
        //if element is ith largest
        if(arr[i] == n-i)
        {
            continue;   //no swap reqd
        }

        //find ith largest element
        int temp = pos_map[n-i];

        pos_map[arr[i]] = temp;
        pos_map[n-i] = i;

        swap(arr[temp], arr[i]);
        k--;
    }
}

int main()
{
    int n,k;
    cin >> n >> k;

    int *arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    k_swap_permutation(arr,n,k);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return (0);
}