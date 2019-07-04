#include<iostream>
using namespace std;

void counting_sort(int *arr, int n)
{
    //find max element to get size of cnt array
    int max_val = -1;
    for(int i=0; i<n; i++)
    {
        max_val = max(arr[i], max_val);
    }

    int cnt_array_size = max_val + 1;
    int *cnt_array = new int[cnt_array_size];
    for(int i=0; i<cnt_array_size; i++)    //set count of every element to zero
    {
        cnt_array[i] = 0;
    }

    //store frequencies of each element
    for(int i=0; i<n; i++)
    {
        cnt_array[arr[i]]++;
    }

    int j=0;        //iterator for original array
    for(int i=0; i<cnt_array_size; i++)     //i is for count array
    {
        int temp = cnt_array[i];
        while(temp--)
        {
            arr[j] = i;
            j++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];
    //take input
    for(int i=0; i<n; i++)
    {
        cin >> input[i];
    }

    counting_sort(input, n);

    //print sorted array
    for(int i=0; i<n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    return (0);
}