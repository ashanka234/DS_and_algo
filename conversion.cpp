#include <iostream>
using namespace std;

int main() 
{
    int max, min, step;
    cin >> min >> max >> step;

    for(int i=min; i<=max; i+=step) 
    {
        float farenheit_val = (float)i;
        //cout << farenheit_val << " ";
        float celcius_val;
        // cout << (farenheit_val - 32) << " " << 5/9 << " ";
        celcius_val = (farenheit_val - 32) * 0.55555;
        cout << farenheit_val << " " << (int)celcius_val << endl;
    }

    return (0);
}