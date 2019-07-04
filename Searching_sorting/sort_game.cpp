#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2)
{
    if(p1.second > p2.second)   //s1 has higher salary
    {
        return true;
    }
    else if(p1.second == p2.second)     //salaries are equal
    {
        if( lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(), p2.first.end()) )
        {
            return false;   //lexicographically s1 < s2
        }
    }
    else    //s2 has higher salary
    {
        return false;
    }
    
}

int main()
{
    int x;
    cin >> x;

    vector< pair<string, int> > v;
    int n;
    cin >> n;
    string name;
    int salary;

    //take inputs
    for(int i=0; i<n; i++)
    {
        cin >> name ;
        cin >> salary;
        pair<string, int> p = make_pair(name, salary);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++)
    {
        if(v[i].second >= x)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }

    return (0);
}