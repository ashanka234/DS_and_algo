#include <iostream>
using namespace std;

int string_to_num(char *arr, int n)
{
    if(n<=0)
        return 0;

    int digit = arr[n-1] - '0';
    //cout << digit << " ";
    return digit + 10*string_to_num(arr, n-1);
}

int main() 
{
    char str[100];
    cin >> str;
    int n;
    for(n=0; str[n]!='\0'; n++);        //calculate length
    //cout << n << endl;
    cout << string_to_num(str, n) << endl;

    return (0);
}