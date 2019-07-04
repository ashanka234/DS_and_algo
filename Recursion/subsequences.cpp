#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void print_subseq(char *input, char *output, int i, int j)
{
    if(input[i] == '\0')
    {
        output[j] = input[i];
        cout << output <<" ";
        return;
    }

    output[j] = input[i];   
    print_subseq(input, output, i+1, j+1);  //take current char
    print_subseq(input, output, i+1, j);    //dont take current
}

int main()
{
    char str[100], ans[100];
    cin >> str;
    
    print_subseq(str, ans, 0, 0);
    cout << "\n" << pow(2,strlen(str)) << endl;

    return (0);
}