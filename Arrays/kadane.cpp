//Largest sum contiguos subarray
#include<iostream>
#include<climits>
using namespace std;

int get_largest_sum(int *arr, int n)
{
    int max_so_far=INT_MIN, max_till_here=0;

    for(int i=0; i<n; i++)
    {
        max_till_here += arr[i];        //including current element

        if(max_till_here > max_so_far)
        {
            max_so_far = max_till_here;
        }

        if(max_till_here < 0)
        {
            max_till_here = 0;
        }
    }

    return max_so_far;
}


int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]);

    cout << get_largest_sum(a, n) << endl;

    return (0);
}