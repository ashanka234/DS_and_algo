#include<iostream>
using namespace std;

int binary_search(int *arr, int n, int key)
{
    int low=0, high=n-1;
    int mid;

    while(low <= high)
    {
        mid = (high+low)/2;
        if(arr[mid] > key)      //search in left half
        {
            high = mid-1;
        }
        else if(arr[mid] < key)     //search right half
        {
            low = mid+1;
        }
        else        //found
        {
            return mid;
        }
    }

    return -1;
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

    int key;
    cin >> key; 

    cout << binary_search(arr, n, key) << endl;

    return (0);
}