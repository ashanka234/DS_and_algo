#include<iostream>
using namespace std;

void reverse_k(int *arr, int n, int k)
{
    int left, right;
    int i=0;

    while(i < n-k+1)
    {   
        left = i;
        right = min(i+k-1, n-1);

        while(left <= right)
        {
            swap(arr[left++], arr[right--]);
        }
        i += k;
    }
}

int main()
{
    int n, t, k;
    int *arr; 

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        reverse_k(arr, n, k);

        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return (0);
}