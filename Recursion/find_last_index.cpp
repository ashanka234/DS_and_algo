#include<iostream>
using namespace std;


int findLastIndex(int *arr, int n, int m)
{
   //base case
   if(n<0)
   {
       return -1;   //not found
   }
   
   if(arr[n] == m)
   {
       return n;
   }
   else 
   {
       return findLastIndex(arr, n-1, m);
   }
}

int main() {
    int n, m;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> input[i];
    }
    cin >> m;


    cout << findLastIndex(input, n, m) << endl;

	return 0;
}