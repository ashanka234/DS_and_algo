#include<iostream>
#include<unordered_map>
using namespace std;

bool isExist(int *arr, int l, int n)
{
    // unordered_map<int, bool> map;
    // for(int i=0; i<l; i++)
    // {
    //     map.insert(make_pair(arr[i],true));
    // }

    // if(map.find(n) == map.end())    //not found
    // {
    //     return false;
    // }
    // else
    // {
    //     return true;
    // }

    int map[100001];
    for(int i=0; i<l; i++)
    {
        map[arr[i]] = 1;
    }

    if(map[n] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

int main()
{
    int t;  //no. of test cases
    cin >> t;
    while(t--)
    {
        int l;  //length of array
        cin >> l;
        int *arr = new int[l];
        for(int i=0; i<l; i++)
        {
            cin >> arr[i];
        }
        
        int q;      //no. of queries
        cin >> q;
        while(q--)
        {
            int n;  //search key
            cin >> n;
            if(isExist(arr,l,n))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return (0);
}