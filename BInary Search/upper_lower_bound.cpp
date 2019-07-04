#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    int x;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int t;
    cin>> t;
    while(t--)
    {
        int y;
        cin >> y;
        if(find(v.begin(), v.end(), y) != v.end())
        {
            cout << lower_bound(v.begin(), v.end(), y) - v.begin() << " ";
            cout << upper_bound(v.begin(), v.end(), y) - v.begin() - 1 << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    return (0);
}
