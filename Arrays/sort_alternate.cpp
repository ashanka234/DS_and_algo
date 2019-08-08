#include<iostream>
using namespace std;

void print_ans(int *arr, int n)
{
    int i=0, j=n-1;
    bool printMax = true;

    while(i<=j)
    {
        if(printMax)
        {
            cout << arr[j--] << " ";
        }
        else
        {
            cout << arr[i++] << " ";
        }
        printMax = !printMax;       
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        int *arr;

        cin >> n;
        arr = new int[n];

        for(int i=0; i<n; i++)
            cin >> arr[i];

        print_ans(arr, n);
        cout << endl;
    }

    return (0);
}