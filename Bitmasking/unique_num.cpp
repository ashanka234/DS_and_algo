#include <iostream>
using namespace std;

int find_unique(int *arr, int n)
{
    int xor_all = 0;
    for(int i=0; i<n; i++)
    {
        xor_all ^= arr[i];
    }

    return xor_all;
}

int main()
{
    int n;
    cin >>n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << find_unique(arr, n) << endl;

    return (0);
}