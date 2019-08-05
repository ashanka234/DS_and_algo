#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int get_min_cost(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++)
        minHeap.push(arr[i]);

    int res = 0;

    while(minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        res += first + second;
        minHeap.push(first + second);
    }

    return res;
}

int main()
{
    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << get_min_cost(arr, n) << endl;

    return (0);
}