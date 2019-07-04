#include<iostream>
using namespace std;

void merge(int *arr, int l, int h)
{
    int mid = (l+h)/2;
    int i=l, j=mid+1, k=l;
    int *temp = new int[h-l+1];

    //arr 1 - l to mid
    //arr 2 - mid+1 to h
    while(i<=mid && j<=h)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    //copy remaining elements if ome array finishes early
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j<=h)
    {
        temp[k++] = arr[j++];
    }

    //copy temp to original
    for(int i=l; i<=h; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int *arr, int l, int h)
{
    if(l >= h)
    {
        return ;
    }
    
    int mid = (l+h)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, h);
    merge(arr,l,h);
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

    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return (0);
}