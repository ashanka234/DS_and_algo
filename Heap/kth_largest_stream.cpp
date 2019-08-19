#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

void get_kth_largest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int count = 0;

    for(int i=0; i<n; i++)
    {
        int x = arr[i];

        if(count < k-1)
        {
            cout << -1 << " ";
            minHeap.push(x);
            count++;
        }
        else if(count == k-1)
        {
            minHeap.push(x);
            cout << minHeap.top() << " ";
            count++;
        }
        else
        {
            if(x > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(x);
            }
            cout << minHeap.top() <<  " ";
            count++;
        }
    }
}

int main()
{
    int n, t, k;
    int *arr;

    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        get_kth_largest(arr, n, k);
        cout << endl;
    }

    return (0);
}