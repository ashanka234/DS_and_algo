#include<iostream>
using namespace std;

int get_missing_num(int *arr, int n)
{
    int sum = ((n+1) * (n+2))/2;
    int curr_sum = 0;

    for(int i=0; i<n; i++)
    {
        curr_sum += arr[i];
    }
    //cout << sum << " " << curr_sum << endl;

    return (sum - curr_sum);
}

//using XOR
int get_missing_num_XOR(int *arr, int n)
{
    int x1 = 0;     //from array
    int x2 = 0;     //actual

    for(int i=0; i<n; i++)
    {
        x1 = x1 ^ arr[i];
    }

    for(int i=1; i<= n+1; i++)
    {
        x2 = x2 ^ i;
    }

    return x1^x2;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6};        //missing 5, numbers 1 to 6, n=5
    int n = sizeof(arr)/sizeof(int);

    cout << get_missing_num(arr, n) << endl;
    cout << get_missing_num_XOR(arr, n) << endl;

    return (0);
}