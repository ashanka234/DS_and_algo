#include<iostream>
using namespace std;

void bubble_sort(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << endl;
    }

    return (0);
}