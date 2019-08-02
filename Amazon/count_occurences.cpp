#include<iostream>
#include<algorithm>
using namespace std;

int get_count(int *arr, int n, int key)
{
    int *low, *high;

    low = lower_bound(arr, arr+n, key);     //get first occurence index
    high = upper_bound(low, arr+n, key);        //get last occurence, searching only in the part of array after low index

    if(low == arr+n || *low != key)
        return 0;       //element is not present in array

    return high - low;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3}; 
    int key = 3;
    int n = sizeof(arr)/sizeof(int);

    cout << get_count(arr, n, key) << endl;

    return (0);
}