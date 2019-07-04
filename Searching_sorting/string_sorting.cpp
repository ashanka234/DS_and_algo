#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> v;
    //take input
    for(int i=0; i<n; i++)
    {
        string in;
        cin >> in;
        v.push_back(in);
    }

    //sort the array
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i].find(v[j]) != string::npos) //found substring
            {
                swap(v[i], v[j]);
            }
        }
    }

    
    //print output array
    for(int i=0; i<n; i++)
    {
        cout << v[i] << endl;
    }

    return (0);
}