#include<iostream>
#include<queue>
using namespace std;

void heapSort_pq(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++)
        minHeap.push(arr[i]);

    while(!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

void heapify(int *arr, int n, int i)
{
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[root])
    {
        root = left;
    }

    if(right < n && arr[right] > arr[root])
    {
        root = right;
    }

    if(root != i)
    {
        swap(arr[i], arr[root]);

        heapify(arr, n, root);
    }
}

void heapSort(int *arr, int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);       //curr root to end

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return (0);
}