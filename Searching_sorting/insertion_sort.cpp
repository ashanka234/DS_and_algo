#include<iostream>
using namespace std;

void insertion_sort(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            //shift 
            arr[j+1] = arr[j];
            j--;
        }
        //insert
        arr[j+1] = temp;
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

    insertion_sort(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << endl;
    }

    return (0);
}