#include <iostream>
using namespace std;

int main() 
{
    char ch;
    cin >> ch;

    while(ch != 'x' && ch != 'X')
    {
        //cin >> ch;
        //cout << ch << " ";
        switch(ch) 
        {
            case '+' : int a, b;
                    cin >> a >> b;
                    cout << a+b << endl;
                    break;

            case '-' : //int a, b;
                    cin >> a >> b;
                    cout << a-b << endl;
                    break;

            case '*' : //int a, b;
                    cin >> a >> b;
                    cout << a*b << endl;
                    break;

            case '/' : //int a, b;
                    cin >> a >> b;
                    cout << a/b << endl;
                    break;

            case '%' : //int a, b;
                    cin >> a >> b;
                    cout << a%b << endl;
                    break;
            default:
                    cout << "Invalid operation. Try again.\n";
        }
        cin >> ch;
    }

    return (0);
   
}