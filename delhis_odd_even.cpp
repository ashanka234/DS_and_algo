#include <iostream>
using namespace std;

//  1=even , 0=odd
int isEven(int n) 
{
    if(n%2 == 0)
        return 1;
    else
        return 0;   //odd
}

int main() 
{
    int t;
    cin >> t;

    while(t--) 
    {
        int num;
        int even_sum=0, odd_sum=0;
        cin >> num;

        while(num) 
        {
            int digit = num%10;
            if( isEven(digit) ) {
                even_sum += digit;
            }
            else {
                odd_sum += digit;
            }
            num = num/10;
        }

        if(even_sum % 4 == 0 )
            cout << "Yes\n";
        else if(odd_sum % 3 == 0)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }

    return (0);
}