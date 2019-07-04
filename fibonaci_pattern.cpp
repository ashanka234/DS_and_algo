#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 11 
int fibo(int n) 
{
    if(n==1 || n==0)    //first fibo is 0
        return 0;

    if(n==2)
        return 1;
    
    return fibo(n-1) + fibo(n-2);

}

int main()
{
    int n;
    cin >> n;
    int max = (n*(n+1))/2;
    // cout << max << endl;

    for(int i=0; i<n; i++)
    {
        int k=i+1;
        for(int j=0; j<=i; j++)
        {
            cout << fibo(k+j) << "\t";
        }
        cout << endl;
    }

    return (0);
}