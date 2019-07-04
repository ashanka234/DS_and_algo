#include <iostream>
using namespace std;

void generate_strings(char *input, char *output, int i, int j)
{
    if(input[i] == '\0')
    {
        output[j] = input[i];
        cout << output << endl;
        return;
    }

    //get number as char
    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    output[j] = ch;
    generate_strings(input, output, i+1, j+1);      //take this digit in combination

    if(input[i+1] != '\0')  //make 2 digit number
    {
        int next_digit = input[i+1] - '0';
        int new_num = digit*10 + next_digit;
        if(new_num <= 26)
        {
            ch = new_num + 'A' - 1;
            output[j] = ch;
            generate_strings(input, output, i+2, j+1);      //take 2 digit number in combination
        }
    }
}

int main()
{
    char str[10], ans[10];
    cin >> str;

    generate_strings(str, ans, 0, 0);

    return (0);
}