#include<iostream>
using namespace std;

void sort_012(int *arr, int n)
{
    int mid=0, low=0, high=n-1;

    while(mid <= high)
    {
        //mid = (high+low)/2;
        switch(arr[mid])
        {
            case 0:     
                swap(arr[low++], arr[mid++]);
                break;

            case 1:
                mid++;
                break;
            
            case 2:
                swap(arr[mid], arr[high--]);
                break;
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
    //cout << 123 <<endl;

    sort_012(arr, n);
    //cout << 456 << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << endl;
    }

    return (0);
}