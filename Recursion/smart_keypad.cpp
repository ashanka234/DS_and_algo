#include <iostream>
using namespace std;

char *table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void print_codes(char *str, char *output, int i, int j)
{
    if(str[i] == '\0')
    {
        output[j] = str[i];
        cout << output << endl;
        return;
    }

    int digit = str[i] - '0';
    for(int k=0; k<strlen(table[digit]); k++)
    {
        output[j] = table[digit][k];
        print_codes(str, output, i+1, j);

    }
}

int main()
{
    char input[10], ans[10];
    cin >> input;

    print_codes(input, ans, 0, 0);

    return (0);
}