#include <iostream>
using namespace std;

int main() 
{
    int num, n;
    int digit_count = 0;

    cin >> num >> n;
    while(num) 
    {
        int digit = num%10;
        if(digit == n)
            digit_count++;
        num = num/10;
    }
    cout << digit_count << endl;

    return (0);
}