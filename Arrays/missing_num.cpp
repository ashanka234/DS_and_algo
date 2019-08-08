#include<iostream>
using namespace std;

int get_missing_num(int *arr, int n)
{
    int normal_xor=0;
    int arr_xor;

    for(int i=1; i<=n; i++)
    {
        normal_xor = normal_xor^i;
    }

    for(int i=0; i<n-1; i++)
    {
        arr_xor = arr_xor^arr[i];
    }

    return normal_xor^arr_xor;
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n-1];

        for(int i=0; i<n-1; i++)
        {
            cin >> arr[i];
        }

        cout << get_missing_num(arr, n) << endl;
    }

    return (0);
}