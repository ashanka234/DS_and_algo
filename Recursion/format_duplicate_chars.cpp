#include <iostream>
using namespace std;

void formatDuplicates(char *arr, char *output, int n)
{
    if(n<0) //base case
    {
        return ;
    }

    if(arr[n-2]==arr[n-1])
    {
        arr[n] = arr[n-1];
        arr[n-1] = '*';
        formatDuplicates()
    }
}

int main()
{
    char str[100], char ans[100];
    cin >> str;
    int n;
    for(n=0; str[n]!='\0';n++); //calcualte length

    return (0);
}