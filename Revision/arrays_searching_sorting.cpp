#include<iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void bubbleSort(int *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}

void selectionSort(int *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_pos = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_pos])
                min_pos = j;
        }
        swap(arr[i], arr[min_pos]);
    }
}

void insertionSort(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = arr[i];

        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int binary_search(int *arr, int n, int key)
{
    int low = 0;
    int high = n-1;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == key)
            return mid+1;

        if(key < arr[mid])
            high = mid-1;

        else if(key > arr[mid])
            low = mid+1;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 1, 5, 7, 2, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    //insertionSort(arr, n);
    printArray(arr, n);

    cout << binary_search(arr, n, 7) << endl;

    return (0);
}