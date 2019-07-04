#include <iostream>
using namespace std;

int main() 
{
    int n, sum=0;

     while(1) {
         cin >> n;
         cout << n <<endl ;
         sum += n;

         if(sum < 0)
             break;
    }

    // cin >> n;
    // cout << "Hello world" << endl;

    return (0);
}