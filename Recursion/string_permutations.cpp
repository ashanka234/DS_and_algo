#include <iostream>
using namespace std;

void print_perm(char *input, int i, int n)
{
    if(i == n-1)
    {
        cout << input << endl;
        return;
    }

    for(int j=i; j<n; j++)
    {
        swap(input[i], input[j]);
        print_perm(input, i+1, n);
        swap(input[i], input[j]);       //restore 
    }
}

int main()
{
    char str[100];
    cin >> str;

    print_perm(str, 0, strlen(str));

    return (0);
}