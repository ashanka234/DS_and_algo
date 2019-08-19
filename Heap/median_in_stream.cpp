#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void getMedian(int *arr, int n)
{
    priority_queue<double> maxHeap;     //store smaller
    priority_queue<double, vector<double>, greater<double> > minHeap;       //store larger 

    double median = arr[0];
    maxHeap.push(arr[0]);

    cout << median << " ";

    for(int i=1; i<n; i++)
    {
        double x = arr[i];

        if(maxHeap.size() > minHeap.size())
        {
            if(x < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
            {
                minHeap.push(x);
            }

            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }

        else if(minHeap.size() > maxHeap.size())
        {
            if(x > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
            else
            {
                maxHeap.push(x);
            }

            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        else
        {
            if(x < median)
            {
                maxHeap.push(x);
                median = (double)maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                median = (double)minHeap.top();
            }
        }

        cout << median << " ";
    }
}

int main()
{
    int n;
    int *arr;

    cin >> n;
    arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    getMedian(arr, n);
    cout << endl;

    return (0);
}