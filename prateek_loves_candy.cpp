#include <iostream>
using namespace std;

bool isPrime(int n) 
{
    if(n<=1)
        return false;
    
    else {
        for(int i=2; i<n; i++) {
            if(n%i == 0)
                return false;
        }
    }
    return true;
}

int main() 
{
    int t;
    cin >> t;

    while(t--) 
    {
        int n, i;
        cin >> n;
        int prime_count = 0;

        for(i=2; ;i++) 
        {
            if(isPrime(i))
                prime_count++;
            
            if(prime_count == n)
                break;
        }
        cout << i << endl;
    }

    return (0);
}