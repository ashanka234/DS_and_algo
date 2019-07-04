#include <iostream>
using namespace std;

void move_x(char *input, char *output, int i, int j, int n)
{
    if(input[i] == '\0')
    {
        output[n+j] = input[i];
        cout << output << endl;
        return;
    }

    if(input[i] == 'x')
    {
        output[n] = 'x';
        move_x(input, output, i+1, j, n-1);
    }
    else
    {
        output[j] = input[i];
        move_x(input, output, i+1, j+1, n);
    }
}

int main()
{
    char str[100];
    char ans[100];
    cin >> str;
    int n = strlen(str);
    //cout << n << " ";
    move_x(str, ans, 0, 0, n-1);

    return (0);
}