#include<iostream>
#include<cstring>
using namespace std;

void reverse(string &str, int i, int j)
{
    if(i <= j)
    {
        swap(str[i], str[j]);
        reverse(str, i+1, j-1);
    }
}

void reverse_words(string &str, int n)
{
    int word_start = 0;
    //cout << str << endl;

    int i = 0;
    while(str[i] != '\0')
    {
        i++;
        if(str[i] == '\0')      //last word
        {
            reverse(str, word_start, i-1);
            //cout << str << endl;
        }

        else if(str[i] == ' ')
        {
            reverse(str, word_start, i-1);
            word_start = i+1;
            //cout << str << endl;
        }
    }


    reverse(str, 0, n-1);
}

int main()
{
    string str;

    getline(cin, str);

    reverse_words(str, str.length());
    //reverse(str, 0, str.length()-1);


    cout << str << endl;

    return (0);
}