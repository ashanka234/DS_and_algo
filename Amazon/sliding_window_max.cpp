#include<iostream>
#include<deque>
using namespace std;

void print_window_max(int *arr, int n, int k)
{
    deque<int> dq(k);       //it will store indexes. not values

    //put first k elements in deque
    int i = 0;
    for(i=0; i<k; i++)
    {
        while(!dq.empty() && arr[i]>arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    //i as at k index now
    for(; i<n; i++)
    {
        cout << arr[dq.front()] << " ";        //this is the largest of previous window

        //current window is from i-k
        while(!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();     //we need to consider only the elemnts within this window
        }

        //now do for current window
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl;     //answer of last window
}

int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr)/sizeof(int);
    int k = 3;

    print_window_max(arr, n, k);

    return (0);
}