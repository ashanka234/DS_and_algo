#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool is_identical(vector<int> &v1, vector<int> &v2, int n)
{
    unordered_map<int, int> hmap;

    for(int i=0; i<n; i++)      //build frequency map
    {
        hmap[v1[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        if(hmap.find(v2[i]) == hmap.end())
            return false;

        if(hmap[v2[i]] == 0)        //matlab v2 mei zyada baar hai than v1
            return false;

        hmap[v2[i]]--;      //decrease count at every occurence 
    }

    return true;
}

int main()
{
    vector<int> v1, v2;
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    //cout << (v1==v2) << endl;
    cout << is_identical(v1, v2, n) << endl;

    return (0);
}