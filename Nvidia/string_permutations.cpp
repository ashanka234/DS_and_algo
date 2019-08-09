#include<iostream>
#include<cstring>
using namespace std;

void print_permutations(char *str, int l, int r)
{   
    if(l == r)      //base case
    {
        cout << str << " ";
        return;
    }

    for(int i=l; i<=r; i++)
    {
        swap(str[i], str[l]);
        print_permutations(str, l+1, r);
        
        //backtrack
        swap(str[i], str[l]);
    }
}

int main()
{
    int t;
    char str[5];

    cin >> t;

    while(t--)
    {
        cin >> str;
        int n = strlen(str);

        print_permutations(str, 0, n-1);
        cout << endl;
    }

    return (0);
}