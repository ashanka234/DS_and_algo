#include<iostream>
#include<queue>
using namespace std;

int kth_largest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int i=0;

    //put first k elements in min heap
    for(i = 0; i<k; i++)
    {
        minHeap.push(arr[i]);
    }

    for(i=k; i<n; i++)
    {
        if(arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    return minHeap.top();
}

int main()
{
    int n=7, k=4;
    int arr[] = {1, 6, 5, 2, 4, 3, 7};

    cout << kth_largest(arr, n, k) << endl;

    return (0);
}