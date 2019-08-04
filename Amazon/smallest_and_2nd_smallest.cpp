#include<iostream>
#include<algorithm>
using namespace std;

void print_2_smallest(int *arr, int n)
{
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(arr[i] < smallest && arr[i] < second_smallest)       //it is new smallest
        {
            second_smallest = smallest;
            smallest = arr[i];
        }

        else if(arr[i] < second_smallest && arr[i] > smallest)      //it is new second smallest
        {
            second_smallest = arr[i];
        }
    }

    cout << smallest << " " << second_smallest << endl;

    return;
}

int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1, 4};
    int n = sizeof(arr) / sizeof(int);

    print_2_smallest(arr, n);
    cout << endl;

    return (0);
}