#include<iostream>
#include<vector>
using namespace std;

bool isOverlap(vector<pair<int, int> > &v)
{
    pair<int, int> l1, r1, l2, r2;
    l1 = v[0];
    r1 = v[1];
    l2 = v[2];
    r2 = v[3];

    if(l1.first > r2.first || l2.first > r1.first)
        return false;

    if(r2.second > l1.second || r1.second > l2.second)
        return false;

    return true;
}

int main()
{
    vector<pair<int, int> > v;

    int t, x, y;

    cin >> t;

    while(t--)
    {
        for(int i=0; i<4; i++)
        {
            cin >> x >> y;
            pair<int, int> p = make_pair(x, y);
            v.push_back(p);    
        }

        cout << isOverlap(v) << endl;
    }

    return (0);
}