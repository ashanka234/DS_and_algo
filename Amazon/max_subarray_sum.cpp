#include<iostream>
#include<climits>
using namespace std;

//Kadane's algorithm
int get_max_subarray_sum(int *arr, int n)
{
    int prev_sum=INT_MIN, curr_sum=0;

    for(int i=0; i<n; i++)
    {
        curr_sum += arr[i];
        if(curr_sum > prev_sum)
            prev_sum = curr_sum;
        
        if(curr_sum < 0)
            curr_sum = 0;
    }

    return prev_sum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << get_max_subarray_sum(arr, n) << endl;

    return (0);
}