#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int a, b, c;
    cin >> a >> b >> c;

    float D = pow(b,2) - (4*a*c);
    

    if(D > 0 )  //real and distinct 
    {
        float x1 = ( (-1*b) + sqrt(D) ) / (2*a);
        float x2 = ( (-1*b) - sqrt(D) ) / (2*a);
        cout << "Real and Distinct\n";
        cout << x2 << " " << x1 << endl;
    }

    else if (D == 0)    //real and equal
    {
        float x1 = (-1*b + sqrt(D) ) / (2*a);
        float x2 = ( -1*b - sqrt(D) ) / (2*a);
        cout << "Real and Equal\n" ;
        cout << x1 << " " << x2 << endl;
    }
    else 
    {
        cout << "Imaginary\n";
    }

    return (0);
}