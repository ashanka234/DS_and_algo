#include<iostream>
#include<unordered_map>
using namespace std;

int  *get_intersection(int *arr1, int *arr2, int n)
{
    unordered_map<int,int> map1;
    unordered_map<int,int> map2;

    int ans[1000];
    int k=0;

    for(int i=0; i<n; i++)
    {
        if(map1.find(arr1[i]) != map1.end())
        {
            map1[arr1[i]]++;
        }
        else
        {
            map1.insert(make_pair(arr1[i], 1));
        }
        
    }

    for(int i=0; i<n; i++)
    {
        if(map2.find(arr2[i]) != map2.end())
        {
            map2[arr2[i]]++;
        }
        else
        {
            map2.insert(make_pair(arr2[i], 1));
        }
        
    }

    for(int i=0; i<n; i++)
    {
        if(map1[arr1[i]] == map2[arr1[i]])
        {
            int x = map1[arr1[i]];
            while(x--)
            {
                ans[k++] = arr1[i];
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];
    int *arr2 = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> arr2[i];
    }

    int *ans = get_intersection(arr1, arr2, n);
    int ans_length = sizeof(ans)/sizeof(int);
    //cout << ans_length << " ";
    
    for(int i=0; i<ans_length; i++)
    {
        cout << ans[i] << " ";
    }

    return (0);
}