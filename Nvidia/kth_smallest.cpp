#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++)
        minHeap.push(arr[i]);

    for(int i=0; i<k-1; i++)
        minHeap.pop();

    return minHeap.top();
}

int kthSmallestOpti(int *arr, int n, int k)
{
    priority_queue<int> maxHeap;

    for(int i=0; i<k; i++)
        maxHeap.push(arr[i]);

    for(int i=k; i<n; i++)
    {
        if(arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

int main()
{
    int t, n, k;
    int *arr;

    cin >> t;
    while(t--)
    {
        cin >> n;
        arr = new int[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        cin >> k;

        cout << kthSmallestOpti(arr, n, k) << endl;
    }

    return (0);
}