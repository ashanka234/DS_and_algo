#include <iostream>
#include <cmath>
using namespace std;


int main() 
{
    
    int num;
    cin >> num;
    int temp = num;
    int length=0;

    //calculate length
    while(temp)
    {
        length++;
        temp /= 10;
    }
    // cout << length <<" ";
    int temp_1 = num, sum=0;

    while(temp_1)
    {
        int digit = temp_1 % 10;
        sum += pow(digit, length);
        temp_1 /= 10;
    }
    
    if(sum == num)
        cout << "true\n";
    else
        cout << "false\n";
    
	return (0);
}