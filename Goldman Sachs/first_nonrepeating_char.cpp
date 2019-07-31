#include<iostream>
#include<cstring>
using namespace std;

char first_nonrepeating_char(char *str, int n)
{
    int count[26] = {0};

    for(int i=0; i<n; i++)
    {
        count[str[i] - 'a']++;
    }

    for(int i=1; i<26; i++)
    {
        if(count[i] == 1)
        {
            char ans = 'a' + i;
            return ans;
        }
    }

    return NULL;
}

int main()
{
    char str[100];
    cin >> str; 
    int n = strlen(str);

    cout << first_nonrepeating_char(str, n) << endl;

    return (0);
}