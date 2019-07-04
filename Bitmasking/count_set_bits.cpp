#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int cnt = 0;

        for(int i=a; i<=b; i++)
        {
            int n = i;
            while(n)
            {
                cnt += n&1;
                n>>=1;
            }
        }
        cout << cnt << endl;
    }

    return (0);
}