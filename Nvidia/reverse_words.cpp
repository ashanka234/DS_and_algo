#include<iostream>
using namespace std;

void reverseUtil(char *left, char *right)
{
    if(left > right)
        return;

    swap(*left, *right);
    reverseUtil(left+1, right-1);
}

void reverse(char *str)
{
    char *word_start = str;
    char *i = str;

    //reverse each word
    while(*i)
    {
        i++;
        if(*i == '\0')      //reached end of string
        {
            reverseUtil(word_start, i-1);
        }
        else if(*i=='.')        //current word ended
        {
            reverseUtil(word_start, i-1);
            word_start = i+1;
        }
    }

    //reverse the whole string
    reverseUtil(str, i-1);
}

int main()
{
    int t;
    char str[2000];

    cin >> t;

    while(t--)
    {
        cin >> str;
        reverse(str);
        cout << str << endl;
    }

    return (0);
}