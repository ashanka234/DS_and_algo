#include<iostream>
using namespace std;

void spiral_print(int arr[][10], int r, int c)
{
    int k=0, l=0;       //starting row and col bounds

    int i, j;       //iterators

    while(k<r && l<c)
    {
        for(j=l; j<c; j++)
            cout << arr[k][j] << " ";       //print kth row 
        k++;

        for(i=k; i<r; i++)
        {
            cout << arr[i][c-1] << " ";
        }
        c--;

        if(k < r)
        {
            for(j=c-1; j>=l; j--)
                cout << arr[r-1][j] << " ";
            r--;
        }

        if(l<c)
        {
            for(i=r-1; i>=k; i--)
                cout << arr[i][l] << " ";
            l++;
        }
    }
}

int main()
{
    int arr[10][10] = {{ 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } };
    int r = 3, c = 6;

    spiral_print(arr, r, c);
    cout << endl;

    return (0);
}