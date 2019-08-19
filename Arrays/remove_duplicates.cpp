#include<iostream>
#include<cstring>
using namespace std;

string remove_duplicates(string str)
{
    int counter=0;  //visited array
    int i=0;        //iterator

    int x, len=0;

    while(i < str.length())
    {
        x = str[i] - 97;

        if( (counter & (1<<x)) == 0)       //mean Xth bit of counter array is unset ie not occured yet
        {
            str[len] = 'a' + x;
            counter = counter | (1<<x); //mark as visited
            len++;
        }

        i++;
    }

    return str.substr(0, len);
}

int main()
{
    string s;
    int t;

    cin >> t;

    while(t--)
    {
        cin >> s;

        //remove_duplicates(s);

        cout << remove_duplicates(s) << endl;
    }

    return (0);
}