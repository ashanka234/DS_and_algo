#include<iostream>
#include<cmath>
using namespace std;

bool find_triplet(int *arr, int n)
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max+1];      //hashmap 
    for(int i=0; i<max+1; i++)
        count[i] = 0;


    //build frequency map
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    for(int i=1; i<max; i++)        //these are the values of A, for which we shall try to find B and C
    {
        if(count[i] == 0)
            continue;       //yeh wala A hai hi nhi; try for next i

        for(int j=1; j<=max; j++)       //these are B values, for which we shall try to find C
        {
            //agar A firse traverse hua and sirf ek hi baar hai array mei, toh try next; ya fir hai hi nhi array mei
            if((i==j && count[j]==1) || count[j]==0)
                continue;

            int val = sqrt(i*i + j*j);      //yeh C hai

            //agar C kuch float aaya tha upar, toh matlab its not a perfect squar
            if((val*val) != (i*i + j*j))
                continue;

            if(val > max)   //out of range
                continue;

            //yha tak pahoch gyde matlab sAyi hai val wala num
            //now check if it exists in array
            if(count[val] != 0)
                return true;        //baat ban gyi
        }
    }

    return false;
}   

int main()
{
    int arr[] = {3, 2, 4, 6, 5};
    int n = sizeof(arr)/sizeof(int);

    cout << find_triplet(arr, n) << endl;

    return (0);
}