//merge 2 sorted arrays in O(1) space
#include<iostream>
using namespace std;

void get_merged(int *a1, int *a2, int m, int n)
{
    for(int i=n-1; i>=0; i--)       //traverse a2
    {
        int j=m-2;      //traverse a1
        int last = a1[m-1];

        while(j>=0 && a1[j]>a2[i])
        {
            a1[j+1] = a1[j];
            j--;
        }

        if(j!=m-2 || a2[i]<last)
        {
            a1[j+1] = a2[j];
            a2[i] = last;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int m, n;
        cin >> m >> n;

        int *arr1 = new int[m];
        int *arr2 = new int[n];

        for(int i=0; i<m; i++)
            cin >> arr1[i];
        for(int i=0; i<n; i++)
            cin >> arr2[i];

        get_merged(arr1, arr2, m, n);

        for(int i=0; i<m; i++)
            cout << arr1[i] << " ";
        for(int i=0; i<n; i++)
            cout << arr2[i] <<  " ";
        cout << endl;
    }

    return (0);
}